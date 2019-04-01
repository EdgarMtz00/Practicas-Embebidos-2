#include <LiquidCrystal.h>

#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8
#define LED 5

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
static String recordMsg; 
bool ledFade = false;
int fadeValue = 0;
char msg[10] = "";

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop(){
  if(ledFade){
    analogWrite(LED, fadeValue);
    fadeValue = (fadeValue + 5) % 255;
  }
  
  if(Serial.available()>0){
    Serial.readBytes(msg, 8);
    String strMsg = msg;
    if (strMsg == "blinkLed"){
        ledFade = !ledFade;
    }else if (strMsg == "showMssg"){
        lcd.clear();
        lcd.print(recordMsg);
    }else if (strMsg == "getsMssg"){
        int TimeOut = 0;
        while(Serial.available() <= 0 || TimeOut <= 50){
          delay(100);
          TimeOut++;
        }
        lcd.clear();
        if(TimeOut < 50){
          Serial.readBytes(msg, 10);
          lcd.print(msg);
        }else{
          lcd.print("error");
        }
    }else if (strMsg ==  "testConn"){
        Serial.write("OK");
        lcd.clear();
        lcd.print("Successful");
        lcd.setCursor(1,0);
        lcd.print("Connection");
    }
  }
  delay(30);
}

