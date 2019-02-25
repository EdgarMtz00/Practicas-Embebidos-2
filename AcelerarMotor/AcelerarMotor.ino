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
int cambioVel, Tmax, vel;


void setup(){
	pinMode(pinCtrl, OUTPUT);
	Tmax = (1 / (mtrFrec * 2))/;
}

void acelerar(){
	
}

void loop(){

}