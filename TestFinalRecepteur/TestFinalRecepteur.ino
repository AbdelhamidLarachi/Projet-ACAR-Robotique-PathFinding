#include <VirtualWire.h>
//*****recepteur*******//

//variables
int broche = 2 ;
int vitesse_bps = 2000;


void setup() {
  Serial.begin(9600);

   vw_setup(vitesse_bps); //vitesse de modulation (2000 baud)Plus la vitesse de communication est lente, plus la portée est élevée
   vw_set_rx_pin(broche);//définir la broche utilisée pour la recpetion
   vw_rx_start(); //commancer lecoute du signial 

   
   
}

void loop() {
  int valeurs[4];
  byte taille_message = sizeof(valeurs);
  
  vw_wait_rx(); // On attend de recevoir quelque chose

  
  if (vw_get_message((byte *) &valeurs, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non

    Serial.print("valeurs[0]=");
    Serial.println(valeurs[0]); // Affiche le message
    Serial.print("valeurs[1]=");
    Serial.println(valeurs[1]); 
    Serial.print("valeurs[2]=");
    Serial.println(valeurs[2]); 
    Serial.print("valeurs[3]=");
    Serial.println(valeurs[3]); 
   
  }
}

