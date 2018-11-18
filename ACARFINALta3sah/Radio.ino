#include <VirtualWire.h>
#include <Crc16.h>
#include "Distance.h"


//**********------**********// Methode d'envoie //**********------**********//
typedef struct {
  uint8_t SOT;
  uint32_t IDEmetteur;
  uint32_t IDRecepteur;
  uint32_t NumTrame;
  uint32_t A;
  uint32_t B;
  uint32_t Distance;
  uint32_t Checksum;
  uint32_t EOT;
} MaStructure;

// soltane.Distance = (counter);

// Déclaration du Crc pour verifier la valeur du Checksum //
Crc16 crcE;
Crc16 crcR;

int NumTrame = 1;



//**********------**********// Méthode d'attente d'accusé de reception //**********------**********//

typedef struct {
  uint8_t SOT;
  uint32_t IDEmetteur;
  uint32_t IDRecepteur;
  uint32_t NumTrame;
  uint32_t EOT;
}Accuse;





bool  accuse(){  
Serial.println("Attente d'accusé");
vw_rx_start();

  if (vw_wait_rx_max(300)) {
     Serial.println("Acusée recu");
     vw_rx_stop();
    return true;
  }
  else {Serial.println("Acusée non recu"); return false;}
  
}


// Méthode d'envoie du trame

void Send(){
  MaStructure soltane;
  soltane.NumTrame = NumTrame;
  soltane.A = start;
  soltane.B = start+1;
  crcE.clearCrc();
  crcE.updateCrc(soltane.A);
  crcE.updateCrc(soltane.B);
  crcE.updateCrc(soltane.Distance);
  soltane.Checksum = crcE.getCrc();
  vw_send((byte*) &soltane, sizeof(soltane)); // On envoie le message
  vw_wait_tx(); // On attend la fin de l'envoi
  NumTrame++;
  Serial.println("SENT! !"); 
   if (!accuse){
    Send();
   }
}

// Accuse de Reception 
int T = 1;
void sendT(){
    vw_send((byte*) &T, sizeof(T));
    vw_wait_tx(); 
}




//**********------**********// Methode de Reception //**********------**********//
void Recieve(){

    MaStructure soltane;
    vw_rx_start(); // On peut maintenant recevoir des messages
    byte taille_message = sizeof(MaStructure);
    vw_wait_rx_max(100);  
    if (vw_get_message((byte *) &soltane, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non
    Serial.print("SOT="); // Affiche le message
    Serial.print(soltane.SOT);
    Serial.print(" ID du Emetteur=");
    Serial.println(soltane.IDEmetteur);
    Serial.print(" ID du Recepteur=");
    Serial.println(soltane.IDRecepteur);
    Serial.print(" Numero de la Trame=");
    Serial.println(soltane.NumTrame);
    Serial.print(" A=");
    Serial.println(soltane.A);
    Serial.print(" B=");
    Serial.println(soltane.B);
    Serial.print(" Distance=");
    Serial.println(soltane.Distance);
    Serial.print(" Checksum=");
    Serial.println(soltane.Checksum);
    Serial.print(" EOT =");
    Serial.println(soltane.EOT);
    delay(1000);
    crcR.clearCrc();
    crcR.updateCrc(soltane.A);
    crcR.updateCrc(soltane.B);
    crcR.updateCrc(soltane.Distance);
    Serial.println(crcR.getCrc());
    Serial.println(soltane.Checksum);
    vw_rx_stop();
    //**********------**********// Vérification du Checksum //**********------**********//
    if(soltane.Checksum == crcR.getCrc()) { 
    sendT();
    sendT();
    sendT();
    sendT();
    sendT();
    sendT();
    Serial.println(" Accusé Envoyé "); 
   }

    if(soltane.Checksum != crcR.getCrc()){ // On envoie le message
      Serial.println (" Check is not Correcrt ");
      Send();
    }
    }
}






