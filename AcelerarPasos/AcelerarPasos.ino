#include <Stepper.h>

const int pinStart = 0;
const int pinMtr0 = 1;
const int pinMtr1 = 2;
const int pinMtr2 = 3;
const int pinMtr3 = 4;
int vel, velMax;
bool acelerar;

Stepper stepper;

void setup(){
	stepper = new Stepper(4, pinMtr0, pinMtr1, pinMtr2, pinMtr3);
	vel = 1
}

void loop(){
	if(digitalRead(pinStart)){
		for(int vel; vel < velMax; vel++){
			if(!acelrar){

			}else{
				
			}
		}
	}
}