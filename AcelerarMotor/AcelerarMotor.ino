#include <LiquidCrystal.h>
#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7); 

const int pinVel = 0;
const int pinDer = 1;
const int pinIzq = 2;
const int pinDir = 5; 
const int pinDown = 6;
const int pinUp = 7;
const int mtrFrec = 2200/60;
int Tmax, vel;
bool dir = 1;


void setup(){
	pinMode(pinVel, OUTPUT);
	Tmax = (1 / (mtrFrec * 2));
	//TODO: cambiar frecuencia del pwm
	vel = 50;
	analogWrite(pinVel, vel);
	cambiarDireccion();
}

//TODO: escribir en la pantalla
void acelerar(int cambio){
	vel += cambio;
	analogWrite(pinVel, vel);
}

void cambiarDireccion(){
	dir != dir;
	if(dir){
		digitalWrite(pinIzq, HIGH);
		digitalWrite(pinDer, LOW);
	}else{
		digitalWrite(pinIzq, LOW);
		digitalWrite(pinDer, HIGH);
	}
}

void loop(){
	if(digitalRead(pinUp)){
		acelerar(10);
	}else if(digitalRead(pinDown)){
		acelerar(-10);
	}else if(digitalRead(pinDir)){
		cambiarDireccion();	
	}
}