#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

int x_angle,y_angle,z_angle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu6050.update();
  x_angle=mpu6050.getAngleX();
  y_angle=mpu6050.getAngleY();
  z_angle=mpu6050.getAngleZ();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  if (x_angle>=40){
    Serial.println('R');
  }
  else if (x_angle<=-40){
    Serial.println('L');
  }
  else if (y_angle>=40){
    Serial.println('F');
  }
  else if (y_angle<=-40){
    Serial.println('B');
  }
  else{
    Serial.println('S');
  }
}
