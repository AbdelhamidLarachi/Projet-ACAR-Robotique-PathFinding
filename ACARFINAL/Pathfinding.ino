#include "Grove_I2C_Motor_Driver.h"
#include <Wire.h>
#define I2C_ADDRESS 0x0f
#include "Movements.h"

// Premier Chemin
int path[15] = {1,2,1,1,2,3,2,2,1,1,2,3,2,3,4};

// Deuxieme Chemin
//int path[16] = {3, 2, 1, 2, 2, 3, 3, 2, 2, 1, 1, 2, 3, 2, 3, 4};
int start = 0;
int fin = 15;

void Pathfinding(){

if ((!etatCapteurGauche) && (!etatCapteurCentreGauche) && (!etatCapteurCentreDroite) && (!etatCapteurDroite)){
Straight();
  }
  



if(((etatCapteurGauche) && (etatCapteurCentreGauche)) || ((etatCapteurDroite) && (etatCapteurCentreDroite))){
  delay(200);
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 0);
      
      if ( start < fin ){

      if (path[start] == 1){
         Left();
       
      }
      
      else if( path[start] == 2){
        Right();
        
       
      }
      
      else if (path[start] == 3 ){
        Straight();
        
       
      }
      else if (path[start] == 4 ){
        Stop();
      }
      start++;
}


else if(((etatCapteurGauche) && (etatCapteurCentreGauche)) || ((etatCapteurDroite) && (etatCapteurCentreDroite))){
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 0);
  delay(500);
      
      if ( start > fin ){

      if (path[start] == 1){
         Right();
       
      }
      
      else if( path[start] == 2){
        Left();
        
       
      }
      
      else if (path[start] == 3 ){
        Straight();
        
       
      }
        else if (path[start] == 4 ){
        Stop();
      }
      }
      start--;
}
}
Deviation();
}
  

