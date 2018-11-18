#include "Radio.h"
float voltage;

int counter = 0;
bool affichage = false;


void docount()
{
  counter++;
}

    void Eclaireur()
    {
      
        voltage = getVoltage();
        if (voltage > 1.6){
if  ( affichage && counter != 0){
 Serial.print(counter);
   Serial.println("CM");
      affichage = false;
      Timer1.detachInterrupt();
     
     }
     counter = 0;
     Timer1.detachInterrupt();

}
  else {
     affichage = true;
      attachInterrupt(0, docount, RISING);
  }
    }
    
    float getVoltage()
    {
        int sensor_value;
        int sum;  
        // read the analog in value:
        for (int i = 0;i < 20;i ++)//Continuous sampling 20 times
        {
            sensor_value = analogRead(IR_PROXIMITY_SENSOR);
            sum += sensor_value;
        }
        sensor_value = sum / 20;
        float voltage;
        voltage = (float)sensor_value*ADC_REF/1024;
        return voltage;
    }
