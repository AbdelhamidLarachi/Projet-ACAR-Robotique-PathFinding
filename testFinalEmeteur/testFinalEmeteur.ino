#include <VirtualWire.h>
//******emeteur******//


//variables
int broche = 2 ;
int vitesse_bps = 2000; // limites 2600 bits par secondes. 

float val1 = 30 ;
float val2 = 20 ;
float val3 = 10.5 ;
float val4 = 11 ;


void setup() {
  Serial.begin(9600);

  vw_setup(vitesse_bps); //vitesse de modulation (2000 baud)vitesse de transmission en bits par seconde.
  vw_set_tx_pin(broche);//définir la broche utilisée pour lemmision

  
 
}

void loop() {
int valeurs[4];
  
  valeurs[0] = val1;
  valeurs[1] = val2;
  valeurs[2] = val3;
  valeurs[3] = val4;
  
  
  vw_send((byte *) &valeurs, sizeof(valeurs)); // On envoie le message
  vw_wait_tx(); // On attend la fin de l'envoi
  
  delay(1000);

}
