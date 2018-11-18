// Les librairies utilisés
#include "Grove_I2C_Motor_Driver.h"
#include <Wire.h>
#define I2C_ADDRESS 0x0f
#include "Movements.h"
#include "Pathfinding.h"
#include <VirtualWire.h>
#define IR_PROXIMITY_SENSOR A0 
#define ADC_REF 5
#include "Distance.h"
#include "Radio.h"
#include "Vitesse.h"



// Déclaration des capteurs

const int capteurGauche = 6;
const int capteurCentreGauche = 7;
const int capteurCentreDroite = 5;
const int capteurDroite = 8;
const int capteurVitesse=4;


// Déclaration d'état du capteur

bool etatCapteurGauche;
bool etatCapteurCentreGauche;
bool etatCapteurCentreDroite;
bool etatCapteurDroite;








void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentreGauche, INPUT);
  pinMode(capteurCentreDroite, INPUT);
  pinMode(capteurDroite, INPUT);
    //Setup capteur de vitesse
      pinMode(capteurVitesse, INPUT); 
  


}

void loop() {
  
  // Attribution aux capteurs une variable booléene
  etatCapteurGauche = digitalRead(capteurGauche);
  etatCapteurCentreGauche = digitalRead(capteurCentreGauche);
  etatCapteurCentreDroite = digitalRead(capteurCentreDroite);
  etatCapteurDroite = digitalRead(capteurDroite);
  

Pathfinding();
Radio();

}
