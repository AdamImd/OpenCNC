#include <Arduino.h>

const int EN_x=21;
const int DIR_x=22;
const int STP_x=23;

const int EN_y=18;
const int DIR_y=19;
const int STP_y=20;

void setup() {
  // put your setup code here, to run once:
  pinMode(EN_x, OUTPUT);
  pinMode(DIR_x, OUTPUT);
  pinMode(STP_x, OUTPUT);
  digitalWrite(EN_x, LOW);
  digitalWrite(DIR_x, LOW);
  digitalWrite(STP_x, LOW);
  

  pinMode(EN_y, OUTPUT);
  pinMode(DIR_y, OUTPUT);
  pinMode(STP_y, OUTPUT);
  digitalWrite(EN_y, LOW);
  digitalWrite(DIR_y, LOW);
  digitalWrite(STP_y, LOW);

  delay(5000);
}

int dir=0;


  digitalWrite(DIR_x,dir);
  digitalWrite(DIR_y,dir);
  int del = 100;
  for(int j=0; j<5000; j++){
    digitalWrite(STP_x, HIGH);
    digitalWrite(STP_y, HIGH);
    delayMicroseconds(del);
    digitalWrite(STP_x, LOW);
    digitalWrite(STP_y, LOW);
    delayMicroseconds(del);
  }
  for(int j=0; j<5000; j++){
    digitalWrite(STP_x, HIGH);
    digitalWrite(STP_y, HIGH);
    delayMicroseconds(del);
    digitalWrite(STP_x, LOW);
    digitalWrite(STP_y, LOW);
    delayMicroseconds(del);
  }

  dir=!dir;
  delay(1000);
}