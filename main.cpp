#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);

Servo xaxis;
Servo yaxis;

float CorrectedX = 0;
float CorrectedY = 0;
float CorrectedZ = 0;
float filtercoef = 0.95;

int posX = 0;
int posY = 0;


void setup() {


  xaxis.attach(26);
  yaxis.attach(25);

  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL - data transfer for the mpu, attach breadboard wires to the respective ports.

  byte status = mpu.begin();  
  while (status != 0) {       
    delay(500);
    status = mpu.begin();
  }

  delay(1000);             
  mpu.calcOffsets(true,true);    
  mpu.setFilterAccCoef(0.99);
}


void loop(){


  mpu.update();
  
  // basic filtering logic, uses prior value with current to reduce noise
  float RawX = mpu.getAngleZ();
  float RawY = mpu.getAngleX();

  CorrectedX = (filtercoef*CorrectedX + (1-filtercoef)*RawX) - 0.009;
  CorrectedY = (filtercoef*CorrectedY + (1-filtercoef)*RawY) - 0.09;
 
  Serial.println(posX);
  //Serial.println(CorrectedY);

  posX = 90 + CorrectedX;
  posY = 90 - CorrectedY;


  xaxis.write(posX);

  yaxis.write(posY);

  delay(5);

}