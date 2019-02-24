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
	cambioVel = Tmax/500;
}

void acelerar(){
	
}

void loop(){

}