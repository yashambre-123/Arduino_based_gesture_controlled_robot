#include <MPU6050_tockn.h>
#include <Wire.h>
int motorpin1=3;
int motorpin2=4;
int motorpin3=5;
int motorpin4=6;
MPU6050 mpu6050(Wire);
char data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  pinMode(motorpin3,OUTPUT);
  pinMode(motorpin4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    data=Serial.read();
    if (data=='F'){
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,HIGH);
      digitalWrite(motorpin4,LOW);
      Serial.println("F");
    }s
    else if (data=='R'){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,HIGH);
      digitalWrite(motorpin4,LOW);
      Serial.println("R");
    }
    else if (data=='L'){
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW);
      digitalWrite(motorpin4,LOW);
      Serial.println("L");
    }
    else if (data=='B'){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,LOW);
      digitalWrite(motorpin4,HIGH);
      Serial.println("B");
    }
    else if (data=='S'){
         digitalWrite(motorpin1,LOW);
         digitalWrite(motorpin2,LOW);
         digitalWrite(motorpin3,LOW);
         digitalWrite(motorpin4,LOW);
         Serial.println("S");
    }
  }
}
