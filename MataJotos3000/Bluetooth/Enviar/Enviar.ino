#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

float x, y, nX, nY;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  x = mpu6050.getAngleX();
  y = mpu6050.getAngleY();
}

void loop() {
  mpu6050.update();
  nX = mpu6050.getAngleX();
  nY = mpu6050.getAngleY();
  if ((x + 25) < nX)
    Serial.println("D"); 
  else if ((x - 25) > nX)
    Serial.println("A");
  else if ((y + 25) < nY)
    Serial.println("L");
  else if ((y - 25) > nY)
    Serial.println("R");
  else
    Serial.println("N");
  delay(100);
}
