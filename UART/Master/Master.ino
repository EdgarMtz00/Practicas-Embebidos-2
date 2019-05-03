#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <Keypad.h>

#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8
#define Rec 7

const byte filas = 4;
const byte columnas = 4;
const int pin = 9;
const int slaves = 2;
byte pinsFilas[filas]={2,3,4,5};
byte pinsColumnas[columnas]={6,7,8,9};
char teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad teclado=Keypad(makeKeymap(teclas),pinsFilas,pinsColumnas,filas,columnas);

LiquidCrystal_I2C lcd(0x27, 20, 4);

String msg = "";
char charMsg[10];
char tecla = NO_KEY;
char slaveId;

void printMenu(){
  lcd.clear();
  lcd.print("1.-Led 2.-Msg");
  lcd.setCursor(0, 1);
  lcd.print("3.-SendMsg 4.-Test");
}

void getId(){
  lcd.clear();
  lcd.print("No. esclavo");
  tecla = NO_KEY;
   while(tecla == NO_KEY){
    tecla = teclado.getKey();
    if(tecla != NO_KEY){
      slaveId = tecla;
      lcd.setCursor(0,1);
      lcd.print(tecla);
      printMenu();
      return;
    }
  }
}

void getText(){
  lcd.clear();
  tecla = NO_KEY;
  while(tecla != '*'){
    tecla = teclado.getKey();
    if(tecla != NO_KEY){
      msg += tecla;
      Serial.print(tecla);
      lcd.print(tecla);
    }
  }
}
 
void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("hola");
  printMenu();
}

void loop(){
  while(tecla == NO_KEY){
    tecla = teclado.getKey();
  }
    lcd.setCursor(0,2);
    lcd.print(tecla);
    switch (tecla){
      case '1':
        getId();
        Serial.print("blinkLed");
        Serial.print(slaveId);
        break;
      case '2':
        getId();
        Serial.write("showMssg");
        Serial.print(slaveId);
        break;
      case '3':
        getId();
        Serial.write("getsMssg");
        Serial.print(slaveId);
        getText();
        delay(1500);
        printMenu();
        msg="";
        break;
      case '4':
        getId();
        Serial.write("testConn");
        Serial.print(slaveId);
        int TimeOut = 0;
        while(Serial.available() == 0 && TimeOut <= 70){
          delay(100);
          TimeOut++;
          lcd.setCursor(0,3);
          lcd.print(Serial.available());
          lcd.setCursor(0,2);
          lcd.print(TimeOut);
        }
        if(TimeOut < 70){
          String strMsg = Serial.readString();
          if(strMsg == "OK"){
            lcd.clear();
            lcd.print("Succesful");
            lcd.setCursor(0,1);
            lcd.print("Connection ");
          }else{
            lcd.clear();
            lcd.print("Wrong");
            lcd.setCursor(0,1);
            lcd.print("Connection");
          }
          strMsg="";
        }else{
          lcd.clear();
          lcd.print("Failed");
          lcd.setCursor(0,1);
          lcd.print("Connection");
        }
        delay(1750);
        printMenu();
        break;
        
    }
    tecla = NO_KEY;
  delay(500);
}
