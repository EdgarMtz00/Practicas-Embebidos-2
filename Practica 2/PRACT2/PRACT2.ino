#include <LiquidCrystal.h>

#define RS 8
#define EN 9
#define D4 10
#define D5 11
#define D6 12
#define D7 13

const int acel = 2;
const int des = 3;
const int cambio = 4;
const int pulso = 5;          //PULSO PWM SE CONECTA AL PIN 8 DEL PUENTE H 
const int pinH2 = 6;        //ENTRADA 2 PUENTE H
const int pinH7 = 7;        //ENTRADA 7 PUENTE H


LiquidCrystal lcd(RS,EN,D4,D5,D6,D7); 

int pot;
bool btnCambio, btnAcel, btnDes, dir;  

void imprimir (){
    lcd.setCursor(0,0);
    lcd.print("                                  ");
    lcd.setCursor(0,0);
    float porcentaje = pot / 2.5;
    lcd.print("* ");
    lcd.print (porcentaje);
    lcd.print("% de potencia *");
}

void bajar(){
  while(pot > 0){
        pot -= 25;
        imprimir();
        delay(500);
        digitalWrite(pulso,pot);
        Serial.println(pot);
      }
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("->");
  pinMode(acel, INPUT);  //+++
  pinMode(des, INPUT);  //---
  pinMode(cambio, INPUT);  //cambio 
  pinMode(pinH2, OUTPUT);
  pinMode(pinH7, OUTPUT);
  pot = 0;
  dir = false;
  Serial.begin(9600);
  Serial.println("hola");
}

void loop() {
  btnAcel = digitalRead(acel);
  btnDes = digitalRead(des);
  btnCambio = digitalRead(cambio);

  if(btnAcel ){                             //++
    pot = (pot >= 250)? pot : pot + 25;   //VALOR DE 10 A CAMBIAR DEPENDIENDO DE LOS PORCENTAJES 
    //analogWrite(pulso,pot);
    imprimir();  
  }  
 
  if(btnDes){                            //--
    pot = (pot != 0)? pot - 25 : pot;   //VALOR DE 10 A CAMBIAR DEPENDIENDO DE LOS PORCENTAJES 
    //analogWrite(pulso,pot);
    imprimir(); 
  }
  
  if(btnCambio){                             //cambio 
    if(dir){             //CAMBIO DE VUELTA
      bajar();
      digitalWrite(pinH2,LOW);  
      digitalWrite(pinH7,HIGH);
      lcd.setCursor(0,1);
      lcd.print("                                            ");
      lcd.setCursor(0,1);
      lcd.print("<-");
    }else{             //CAMBIO DE VUELTA
      bajar();
      digitalWrite(pinH2,HIGH);
      digitalWrite(pinH7,LOW);
      lcd.setCursor(0,1);
      lcd.print("                                            ");
      lcd.setCursor(0,1);
      lcd.print("->");
    }
    dir = !dir; 
    Serial.println("ahhh");   
  }
  delay(1000);
  Serial.println(pot);
  analogWrite(pulso,pot);
}
