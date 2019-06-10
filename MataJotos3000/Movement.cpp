#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "Directions.h"



class Movement{
    int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
   /*
    * 2, 3 izquierda delantera
    * 4, 5 derecha delantera
    * 6, 7 izquierda trasera
    * 8, 9 derecha trasera
    */
    int speed;
    int speedPin = 10;

    public:
    void move(char d){
      Direction dir = getDirection(d);
        switch (dir){
            case Front:
                for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i+=2){
                    digitalWrite(pins[i], HIGH);
                    digitalWrite(pins[i+1], LOW);
                }
                break;
            case Back:
                for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i+=2){
                    digitalWrite(pins[i], LOW);
                    digitalWrite(pins[i+1], HIGH);
                }
                break;
            case Left:
                digitalWrite(pins[0], HIGH);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case Right:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], HIGH);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case FullLeft:
                digitalWrite(pins[0], HIGH);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], LOW);
                break;
            case FullRight:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], HIGH);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case BackRight:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], HIGH);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], HIGH);
                break;
            case BackLeft:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], HIGH);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], HIGH);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], LOW);
                break;
            default:
                break;
        }
    }

    Direction getDirection(char s){
      if(s == "F"){//FrontR
          return Direction::Front;
      }else if(s == "B"){//Back
          return Direction::Back;
      }else if(s == "l"){//left
          return Direction::Left;
      }else if(s == "r"){//right
          return Direction::Right;
      }else if(s == "L"){//FullLeft 
          return Direction::FullLeft;
      }else if(s ==  "R"){//FullRight
          return Direction::FullRight;
      }else if(s ==  "i"){ //BackLeft
          return Direction::BackLeft;
      }else if(s == "d"){//BackRight
          return Direction::BackRight;
      }
    }
    
    void setSpeed(int speed){
        speed = speed % 255;
        analogWrite(speedPin, speed);
    }

    void entrada(){
        for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++){
            pinMode(pins[i], OUTPUT);
        }
        Serial.print("entrada");
        setSpeed(254);
        move(BackLeft);
        delay(1000);
        move(Left);
        delay(1000);
        move(BackRight);
        delay(1000);
        move(Right);
        delay(3000);
    }
};
