int inByte;

 
void setup() {
  Serial.begin(9600);
 }

void loop() {
  if (Serial.available() > 0)       
 inByte = Serial.read();    
if (inByte >= 'A' && inByte <= 'M')        //décaler les lettres (13)
            {
        inByte += 13; 
            }
         else if (inByte >= 'N' && inByte <= 'Z')
            {
            inByte -= 13;
            }
         else if (inByte >= 'a' && inByte <= 'm')
            {
            inByte += 13;
            }
         else if (inByte >= 'n' && inByte <= 'z')
            {
            inByte -= 13;
            }

            if(!isAlpha(inByte)){

              if (inByte >= '0' && inByte <= '4') {  //décaler les Chiffres (5)

                inByte +=5;
              }

              else if (inByte >= '5' && inByte <= '9') {

                inByte -=5;
              }
            }
         Serial.write(inByte);  
         }

} 


