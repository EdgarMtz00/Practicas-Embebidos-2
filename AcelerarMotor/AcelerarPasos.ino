#include <AccelStepper.h>
const int pinStart = 0;
const int pinMtr0 = 1;
const int pinMtr1 = 2;
const int pinMtr2 = 3;
const int pinMtr3 = 4;
uint32_t period;       // 5 minutes


void setup(){
	AccelStepper motor = new AccelStepper(4, pinMtr0, pinMtr1, pinMtr2, pinMtr3);
	motor.setMaxSpeed(1000);
	motor.setAcceleration(motor.maxSpeed()/5)	
}

void loop(){
	if()
	period = 5 * 60000L;
	for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
   		doStuff();
   		moreStuff();
	}

}

