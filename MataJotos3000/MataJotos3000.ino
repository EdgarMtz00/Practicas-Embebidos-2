#include "Movement.cpp"
#include "BTControl.cpp"
#include "SelfControl.cpp"
#define pinSwitch 11 //verde
#define pinPower A2

Movement moves;
BTControl control;
SelfControl autom;
bool power = false;
bool mode = false;

void setup(){
  pinMode(pinSwitch, INPUT);
  pinMode(pinPower, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(pinPower)){
    delay(150);
      power = !power;
      Serial.println(power);
      if (power)
        delay(5000);
  }
  if(digitalRead(pinSwitch)){
    delay(150);
      mode = !mode;
  }
  if(power){
    if(mode)  {
      moves.move(control.getCommand());
      Serial.println("control");
    }else{
      char m = autom.run();
      moves.move(m);
      moves.setSpeed(autom.getSpeed());
      Serial.println("AUTO.................................................");
      if (m=='B'){
        delay(600);
      }
    }
  }else{
    moves.move('n');
  }
}
