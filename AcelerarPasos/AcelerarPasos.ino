#include <AccelStepper.h>
const int pinStart = 0;
const int pinMtr0 = 1;
const int pinMtr1 = 2;
const int pinMtr2 = 3;
const int pinMtr3 = 4;
uint32_t period;


void setup(){
	AccelStepper motor = new AccelStepper(4, pinMtr0, pinMtr1, pinMtr2, pinMtr3);
	motor.setMaxSpeed(1000);
	motor.setAcceleration(motor.maxSpeed()/5)	
}

void loop(){
	if(digitalRead(pinStart)){
		period = 10 * 1000L;
		for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
			motor.move(5);
	   		motor.run();
		}
	}
}

