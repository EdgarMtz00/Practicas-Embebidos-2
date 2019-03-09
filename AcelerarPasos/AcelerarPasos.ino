#include <Stepper.h>

const int pinStart = 2;
const int pinMtr0 = 3;
const int pinMtr1 = 4;
const int pinMtr2 = 5;
const int pinMtr3 = 6;
int retardo;
bool acelerar;

Stepper stepper (2038, pinMtr0, pinMtr1, pinMtr2, pinMtr3);


void setup(){
  Serial.begin(19200);
  acelerar = false;
  stepper.setSpeed(200);
  pinMode(pinStart, INPUT);
  stepper.setSpeed(6);
}

void loop(){
	if(digitalRead(pinStart)!=HIGH){
    Serial.print("AHHHH");
		acelerar = !acelerar;
		if(acelerar){
      Serial.print("accelera");
			retardo=500;
     		while (retardo>=100){
         		stepper.step(1); 
         		delay(retardo);
            retardo = retardo - 1;
        	} 
         while(digitalRead(pinStart)!=HIGH){
            stepper.step(1);
            delay(retardo);
         }
		}else{
			while(retardo<=500){
				stepper.step(1);
				delay(retardo);
				retardo = retardo + 2;
			}
		}
   delay(300);
	}
}
