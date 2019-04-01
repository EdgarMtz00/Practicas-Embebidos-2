#include <LiquidCrystal.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8
#define Rec 13

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
IRrecv receptor(Rec);
decode_results resultados;

String msg = "";
char charMsg[10];

void printMenu(){
  lcd.clear();
  lcd.print("1.-Led 2.-Msg");
  lcd.setCursor(0, 1);
  lcd.print("3.-SendMsg 4.-Test");
}

void getText(){
  receptor.resume();
  int i = 0;
  bool pwr = true;
  while(pwr || i < 10){
    if(receptor.decode(&resultados)){
      switch(resultados.value){
        case 0xFF6897:
          msg += '0';
          lcd.print('0');
          i++;
          break;
        case 0xFF30CF:
          msg += '1';
          lcd.print('1');
          i++;
          break;
        case 0xFF18E7:
          msg += '2';
          lcd.print('2');
          i++;
          break;
        case 0xFF7A85:
          msg += '3';
          lcd.print('3');
          i++;
          break;
        case 0xFF10EF:
          msg += '4';
          lcd.print('4');
          i++;
          break;
        case 0xFF38C7:
          msg += '5';
          lcd.print('5');
          i++;
          break;
        case 0xFF5AA5:
          msg += '6';
          lcd.print('6');
          i++;
          break;
        case 0xFF42BD:
          msg += '7';
          lcd.print('7');
          i++;
          break;
        case 0xFF4AB5:
          msg += '8';
          lcd.print('8');
          i++;
          break;
        case 0xFF52AD:
          msg += '9';
          lcd.print('9');
          i++;
          break;
        case 0xFFA25D:
          pwr = false;
      }
    }
    receptor.resume();
    delay(500);
  }
}
 
void setup(){
  Serial.begin(9600);
  receptor.enableIRIn();
  lcd.begin(16, 2);
  printMenu();
}

void loop(){
	if(receptor.decode(&resultados)){
    switch (resultados.value){
      case 0xFF6897:              
        Serial.write("blinkLed");
        break;
        
      case 0xFF30CF:
        Serial.write("showMssg");
        break;
        
      case 0xFF18E7:
        lcd.clear();
        lcd.print("write:");
        lcd.setCursor(0,1);
        getText();
        Serial.write("getsMssg");   
        Serial.print(msg);
        printMenu();
        break;
        
      case 0xFF10EF:
        Serial.write("testConn");
        int TimeOut = 0;
        while(Serial.available() <= 0 || TimeOut <= 50){
          delay(100);
          TimeOut++;
        }
        if(TimeOut < 50){
          Serial.readBytes(charMsg, 2);
          if(charMsg == "OK"){
            lcd.clear();
            lcd.print("Succesful");
            lcd.setCursor(1,0);
            lcd.print("Connection");
          }else{
            lcd.clear();
            lcd.print("Wrong");
            lcd.setCursor(1,0);
            lcd.print("Connection");
          }
        }else{
          lcd.clear();
          lcd.print("Failed");
          lcd.setCursor(1,0);
          lcd.print("Connection");
        }
        delay(1250);
        printMenu();
        break;
    }
    receptor.resume();
  }
  delay(500);
}
