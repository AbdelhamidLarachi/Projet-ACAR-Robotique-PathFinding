 #define IR_PROXIMITY_SENSOR A0 
    #define ADC_REF 5
    float voltage;
 

    void Eclaireur()
    {
        voltage = getVoltage();
        Serial.print(" " ) ;  
         if((voltage<1.60)) {Serial.print("kayen plassa \n");}
        else{Serial.print("khtik \n ");}     
        //wait 500 milliseconds before the next loop
        delay (300);
    }
    /****************************************************************************/
    /*Function: Get voltage from the sensor pin that is connected with analog pin*/
    /*Parameter:-void                                                       */
    /*Return:   -float,the voltage of the analog pin                        */
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
        //float d;

       
        
        voltage = (float)sensor_value*ADC_REF/1024;
        //d=-voltage*222.22+57;
        return voltage;
    }
