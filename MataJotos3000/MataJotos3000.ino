#include "Movement.cpp"
#include "BTControl.cpp"

Movement moves;
BTControl control;
  
void setup(){
  Serial.begin(9600);
  moves.entrada();
}

void loop(){
  moves.move(control.getCommand());
}
