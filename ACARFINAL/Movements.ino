// Librairies 
#include "Grove_I2C_Motor_Driver.h"
#include <Wire.h>
#define I2C_ADDRESS 0x0f

//Booléen faisant partie de la congifuration de la rotation
bool black;



// La méthode de rotation à gauche
void Left(){
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
  delay(500);
  
for( int i = 0; i < 900; i++){       
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2,-20); 
    if(digitalRead(capteurCentreGauche) == 1 ){ 
        black = true;
        }
if((digitalRead(capteurCentreGauche) == 0) && (digitalRead(capteurCentreDroite) == 0 )&& black){ 

   Motor.speed(MOTOR1, 100);
   Motor.speed(MOTOR2, 100);
   black = false;
   break;
}   
  }
    }

// La méthode de rotation à droite

void Right(){
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
  delay(500);
 for( int i=0 ; i < 900; i++) {

  Motor.speed(MOTOR1, -20);
  Motor.speed(MOTOR2, 100);
    if ( digitalRead(capteurCentreDroite) == 1){
        black = true;    
  }
  if((digitalRead(capteurCentreGauche)== 0) && (digitalRead(capteurCentreDroite) == 0 )&& black) {

   Motor.speed(MOTOR1, 100);
   Motor.speed(MOTOR2, 100);
   black = false;
   break;
}   
  }
    }

// La méthode tout droit

void Straight(){
  Motor.speed(MOTOR1, 60);
  Motor.speed(MOTOR2, 60);
  

}

// Methode D'arret
void Stop(){
  
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
  
}
// Méthode de correction "Les Déviations" : 

void Deviation(){
  
// Si le capteur extreme Gauche détecte du noir : 
if ((etatCapteurGauche)){
  Motor.speed(MOTOR1, 100 );
  Motor.speed(MOTOR2, 0 );
  
}

// Si le capteur extreme Droite détecte du noir : 
else if ((etatCapteurDroite)){


  Motor.speed(MOTOR1, 0 );
  Motor.speed(MOTOR2, 100);
}

// Si le capteur centre du gauche détecte du noir dans le cas de déviation 
else if ((etatCapteurCentreGauche)){

  
Motor.speed(MOTOR1, 80);
Motor.speed(MOTOR2, -20);
}

// Si le capteur centre du droite détecte du noir dans le cas de déviation 
else if ((etatCapteurCentreDroite)){

Motor.speed(MOTOR1, -20);
Motor.speed(MOTOR2, 80);
  
}

}    
