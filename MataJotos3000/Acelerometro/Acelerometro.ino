#include "MPU6050.h"

MPU6050 sensor;

String lastDir;
String frontDir[5] = {"L", "l", "F", "r", "R"};
String backDir[5] = {"i", "i", "B", "d", "d"};

int16_t ax, ay, az;
int16_t minAx = -15000;
int16_t maxAx = 15000;

String getDirection() {
  sensor.getAcceleration(&ax, &ay, &az);
  int i = 0;
  for (float offset = 0; offset <= 2; offset += .5) {
    if (ax <= minAx + (offset * maxAx )) {
      if (az >= 0) {
        lastDir = frontDir[i];
        return lastDir;
      } else {
        lastDir = backDir[i];
        return lastDir;
      }
    }
    i++;
  } 
  return lastDir;
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  sensor.initialize();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String result = getDirection();
  Serial.println(result);
  delay(500);
}
