  #include <VirtualWire.h>
  #include "Distance.h"

    int RF_TX_PIN = 2;
    int t = 0;
    int result;


void Radio(){

      while(voltage<1.60){
        
      }

        Serial.print(result);
          vw_set_tx_pin(RF_TX_PIN);
          vw_setup(2000); 
      const char *msg = "hello";
      vw_send((uint8_t *)msg, strlen(msg));
      delay(400);

    }
