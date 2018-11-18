// Pins utilisé
#include "Distance.h"

int lumiere; 
int tour=0; 
float trmin; 
unsigned long temps;  


int stock[6];

void Vitesse() {

  
while(voltage<1.60){


  temps=millis();
  lumiere = digitalRead(capteurVitesse);
  if (lumiere == LOW) {
    tour=tour+1;

    if ((millis() - temps) > 1000){
    trmin=tour/(millis()-temps)*60000.0; 
    temps=millis();
    tour=0;
      }
    }
  }
  Serial.print("La distance est de : ");
    Serial.println(trmin);
    stock[1] == t;
}
