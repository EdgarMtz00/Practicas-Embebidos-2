#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <NewPing.h>


#define echo 12
#define tpin 13
#define maxDist 50


class SelfControl{
  public:
  SelfControl(){
    pinMode(A5, INPUT);
    pinMode(A4, INPUT);
  }
  
  NewPing sonar = NewPing(tpin,echo,maxDist);
  char front = 'F';
  char back = 'B';
  char left = 'l';
  char fullLeft = 'L';
  char right = 'r';
  char fullRight = 'R';
  char backLeft = 'i';
  char backRight = 'd';
  int  i = 0;
  int contador = 0;
  int speed;
  
  char run(){
    char res;
    if(digitalRead(A5)){
      Serial.println("Negro Atrás");
      contador++;
      if(contador == 3){
        contador = 0;
        res = right;
        speed = 200;
      }else{
        res = front;
        speed = 200;
      }
    }else if(digitalRead(A4)){
      Serial.println("Negro Adelante");
        res = back;
        speed = 200;
    }else{
      int dist = sonar.ping_cm();
      Serial.println(dist);
      if(dist <= 25 && dist != 0){
        res = front;
        speed = 100;
      }else{
        res = fullRight;
        speed = 225;
      }
    }
    return res;
  }
  int getSpeed(){
    return speed;
  }
};
