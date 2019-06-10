#include "Movement.cpp"
#include "BTControl.cpp"

Movement moves;
BTControl control;
  
void setup(){
  moves.entrada();
}

void loop(){
  moves.move(control.getCommand());
}
