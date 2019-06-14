#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
         
class BTControl{
  public: 
    BTControl(){
        Serial.begin(9600); 
    }

    char getCommand(){
      if(Serial.available()){
        char Read = Serial.read();
        return Read;
      }else{
        return '0';
      }
    }
};
