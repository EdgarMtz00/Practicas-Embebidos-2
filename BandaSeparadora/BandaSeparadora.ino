#include <Servo.h>

Servo servo;

const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;    
int rojo = 0;  
int verde = 0;  
int azul = 0;
int pasos = 0;
int golpes[4];
bool colorFlag = false;  
bool r=false, g=false, b=false;

void paso(){
  for(int i = 0; i <=450; i++){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(5);   
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, HIGH);            
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
    }
}

void addGolpe(int value){
  int temp
  for(int i = (sizeof(golpes)/sizeof(*golpes))-1; i >= 0 ; i--){
    golpes[i+1] = golpes[i];
  }
  golpes[0] = value;
}
  
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  
  if (rojo < azul && verde > azul && rojo < 35){  
    r=true;
    addGolpe(140);
    Serial.println("   Rojo");    
  }else if (azul < rojo && azul < verde && verde < rojo){  
    b=true;
    addGolpe(40);
    Serial.println("   Azul");        
  }else if (rojo > verde && azul > verde ){  
    addGolpe(0);      
    Serial.println("   Verde");
  }else{
    addGolpe(0);
    Serial.println("  ");  
  }
  delay(900);  
}


int pasosRojos = 0, pasosAzul = 0;
void putazo(){
  if(golpes[4]!=0){
    servo.write(golpes[4]);
    delay(100);
    if(golpes[3] == 45)
      servo.write(140);
    else if(golpes[3]==140){
      servo.write(40);
    }
  }
}

void setup(){  
  Serial.begin(9600); 
  servo.attach(6);
  servo.write(140);
  //sensor de color
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH); 
  //motor a pasos
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
   
}  
   
void loop(){  
    paso();
    delay(250);
    putazo();
    color();
}