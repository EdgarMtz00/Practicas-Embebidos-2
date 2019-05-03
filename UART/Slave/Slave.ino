# include <LiquidCrystal.h>

#define RS 13
#define EN 12
#define D4 11
#define D5 10 
#define D6 9
#define D7 8
#define LED 5

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
static String recordMsg = "MENSAJE"; 
bool ledFade = false;
int fadeValue = 0;
char msg[10] = "";

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Hola");
}

void loop(){
  if(ledFade){
    analogWrite(LED, fadeValue);
    fadeValue = (fadeValue + 2) % 255;
    lcd.setCursor(0,1);
    lcd.print(fadeValue);
  }
  
  if(Serial.available()>0){
    delay(100); 
    String strMsg = Serial.readString();
    if (strMsg == "blinkLed2"){
        ledFade = !ledFade;
    }else if (strMsg == "showMssg2"){
        lcd.clear();
        lcd.print(recordMsg);
        delay(1500);
    }else if (strMsg == "getsMssg2"){
        lcd.clear();
        lcd.print("Recibiendo mensaje");
        int timeOut = 0;
        while(Serial.available() == 0 && timeOut <= 50){
          delay(100);
          timeOut++;
          lcd.setCursor(0,1);
          lcd.print(timeOut);
        }
        lcd.clear();
        if(timeOut < 50){
          char c[];
          while(Serial.available() > 0 && c != '*'){
            Serial.readBytes(c);
            lcd.print(c);
          }
        }else{
          lcd.print("error");
        }
        delay(1500);
    }else if (strMsg ==  "testConn2"){
        delay(2000);
        Serial.write("OK");
        lcd.clear();
        lcd.print("Successful");
        lcd.setCursor(0,1);
        lcd.print("Connection");
        delay(1500);
        lcd.clear();
    }
    strMsg="";
  }
  delay(30);
}
