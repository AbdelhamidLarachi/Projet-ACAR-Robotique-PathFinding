#include <Crc16.h>
#include <FreqCount.h>
#include "TimerOne.h"
// Les librairies utilisés
#include "Grove_I2C_Motor_Driver.h"
#include <Wire.h>
#define I2C_ADDRESS 0x0f
#include "Movements.h"
#include "Pathfinding.h"
#include <VirtualWire.h>
#define IR_PROXIMITY_SENSOR A1 
#define ADC_REF 5
#include "Distance.h"
#include "Radio.h"


 
volatile unsigned int Mesure; //variable qui compte le nombre de mesures
volatile float trmin; // variable qui affichera la vitesse du disque en tour/min
volatile unsigned long temps; //sert à déterminer le temps que met le disque pour réaliser exactement un tour
volatile int tour; //compte le nombre de tours du disque
volatile const int n=100;  //nombre de tours du disque avant de faire le calcul de vitesse
volatile unsigned long dT;


// Déclaration des capteurs

const int capteurGauche = 6;
const int capteurCentreGauche = 7;
const int capteurCentreDroite = 5;
const int capteurDroite = 8;
const int capteurVitesse=3;


// Déclaration d'état du capteur

bool etatCapteurGauche;
bool etatCapteurCentreGauche;
bool etatCapteurCentreDroite;
bool etatCapteurDroite;


//radio


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentreGauche, INPUT);
  pinMode(capteurCentreDroite, INPUT);
  pinMode(capteurDroite, INPUT);
  
    //Setup capteur de vitesse
    pinMode(capteurVitesse, INPUT); //connection du capteur au pin2 de l'arduino 
    Timer1.initialize(10000); 
 
  //on appelle la fonction NouveauTourInterrupt dès qu'il y a un changement d'état abscence(HIGH) vers présence(LOW) du trou du disque, c'est à dire dès que le disque fait exactement un tour
  //attachInterrupt(interruption,fonction,mode)
//  attachInterrupt(0,nouveauTourInterrupt,FALLING);



// Transmission pin : 
vw_set_tx_pin(2);
// Reception pin : 
vw_set_rx_pin(4);
vw_setup(2000);
      
}




void loop() {
  
  // Attribution aux capteurs une variable booléene
  etatCapteurGauche = digitalRead(capteurGauche);
  etatCapteurCentreGauche = digitalRead(capteurCentreGauche);
  etatCapteurCentreDroite = digitalRead(capteurCentreDroite);
  etatCapteurDroite = digitalRead(capteurDroite);


Pathfinding();
Recieve();
docount();

}
