#include <LiquidCrystal.h>
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
byte pinsFilas[filas]={0,1,2,3};
byte pinsColumnas[columnas]={4,5,6,7};
char teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad teclado=Keypad(makeKeymap(teclas),pinsFilas,pinsColumnas,filas,columnas);

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
//IRrecv receptor(Rec);
//decode_results resultados;

String msg = "";
char charMsg[10];
char Key = NO_KEY;

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
  while(tecla == NO_KEY){
    tecla = teclado.getKey();
  }
	//if(receptor.decode(&resultados)){
    //switch (resultados.value){
    switch (tecla){
      //case 0xFF6897:              
      case '1':
        Serial.write("blinkLed");
        break;
        
      //case 0xFF30CF:
      case '2':
        Serial.write("showMssg");
        break;
        
      //case 0xFF18E7:
      case '3':
        lcd.clear();
        lcd.print("write:");
        lcd.setCursor(0,1);
        getText();
        Serial.write("getsMssg");   
        Serial.print(msg);
        printMenu();
        break;
        
      //case 0xFF10EF:
      case '4':
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
  delay(500);
}
