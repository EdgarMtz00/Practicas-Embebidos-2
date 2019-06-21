#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "Directions.h"
#include <Servo.h>


class Movement{

  public: 
    Servo servo1;
    Servo servo2;
    Movement(){
      servo1.attach(A0);
      servo2.attach(A1);
    }

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
      if (d == '0' || d == ' ')
        return;
      Direction dir = getDirection(d);
      Serial.print(d);
        switch (dir){
            case Front:
                Serial.println("Front");
                Serial.println(speed);
                for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i+=2){
                    digitalWrite(pins[i], HIGH);
                    digitalWrite(pins[i+1], LOW);
                }
                break;
            case Back:
                Serial.println("Back");
                for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i+=2){
                    digitalWrite(pins[i], LOW);
                    digitalWrite(pins[i+1], HIGH);
                }
                break;
            case Left:
                Serial.println("Left");
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
                Serial.println("Right");
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
                Serial.println("FullLeft");
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
                Serial.println("FullRight");
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
                Serial.println("BackRight");
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
                Serial.println("BackLeft");
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], HIGH);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], HIGH);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], LOW);
                break;
            case NONE:
                for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i+=2){
                    digitalWrite(pins[i], LOW);
                    digitalWrite(pins[i+1], LOW);
                }
                break;
            default:
                break;
        }
    }

    Direction getDirection(char s){
      if(s == 'F'){//Front
          return Direction::Front;
      }else if(s == 'B'){//Back
          return Direction::Back;
      }else if(s == 'l'){//left
          return Direction::Left;
      }else if(s == 'r'){//right
          return Direction::Right;
      }else if(s == 'L'){//FullLeft 
          return Direction::FullLeft;
      }else if(s ==  'R'){//FullRight
          return Direction::FullRight;
      }else if(s ==  'i'){ //BackLeft
          return Direction::BackLeft;
      }else if(s == 'd'){//BackRight
          return Direction::BackRight;
      }
      return Direction::NONE;
    }
    
    void setSpeed(int s){
         speed = s % 255;
        analogWrite(speedPin, speed);
    }

    void entrada(){
        for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++){
            pinMode(pins[i], OUTPUT);
        }
        Serial.print("entrada");
        setSpeed(115);
        //madrazos();
        delay(300);
        move(BackLeft);
        delay(1000);
        //madrazos();
        delay(300);
        move(Left);
        delay(1000);
        //madrazos();
        delay(300);
        move(BackRight);
        delay(1000);
        //madrazos();
        delay(300);
        move(Right);
        delay(5000);
    }

    void madrazos(){
        for(int i = 0; i < 2; i++){
          delay(250);
          servo1.write(100);
          servo2.write(85);
          delay(250);
          servo1.write(115);
          servo2.write(115);
        }
        servo1.write(115);
        servo2.write(95);
    }

    void modo_diablo(){
      servo1.write(100);
      servo2.write(100);
    }
};
