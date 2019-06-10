#include <Servo.h>

#define M1N 2
#define M1P 3
#define M2N 4
#define M2P 5
#define M4N 6
#define M4P 7
#define M3N 8
#define M3P 9

void setup() {
  for(int x = 2 ; x < 10; x++)
  pinMode(x,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
  char Read = Serial.read();
  Serial.println(Read);

  if(Read == 'N'){
    for(int x = 2; x < 10; x= x+2){
      analogWrite(x,0);
      analogWrite(x+1,0);
      Serial.println("ALTO");
    }  
  }
  
  else if(Read == 'D'){    
    analogWrite(M1P,0);
    analogWrite(M1N,255);
    analogWrite(M2P,255);
    analogWrite(M2N,0);
    analogWrite(M3P,0);
    analogWrite(M3N,255);
    analogWrite(M4P,255);
    analogWrite(M4N,0);
    Serial.println("DELANTE");
  }
  else if(Read == 'A')
  {
    analogWrite(M1P,255);
    analogWrite(M1N,0);
    analogWrite(M2P,0);
    analogWrite(M2N,255);
    analogWrite(M3P,255);
    analogWrite(M3N,0);
    analogWrite(M4P,0);
    analogWrite(M4N,255);
    Serial.println("ATRAS");
  }  
    else if(Read == 'L')
  {
    analogWrite(M1P,0);
    analogWrite(M1N,0);
    analogWrite(M2P,0);
    analogWrite(M2N,0);
    analogWrite(M3P,175);
    analogWrite(M3N,0);
    analogWrite(M4P,0);
    analogWrite(M4N,255);
    Serial.println("IZQUIERDA");
  }
  else if(Read == 'R')
  {
    analogWrite(M1P,0);
    analogWrite(M1N,0);
    analogWrite(M2P,0);
    analogWrite(M2N,0);
    analogWrite(M3P,0);
    analogWrite(M3N,255);
    analogWrite(M4P,175);
    analogWrite(M4N,0);
    Serial.println("DERECHA");
  }
 }
}
