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
}

int dir=0;

void loop() {
  //---------
//  const int NUM=800;
//  const int DEL=20;
//  digitalWrite(EN, LOW);
//  digitalWrite(DIR,dir);
//  for(int i=0; i<NUM; i++){
//    digitalWrite(STP, HIGH);
//    delayMicroseconds(DEL+i/100);
//    digitalWrite(STP, LOW);
//    delayMicroseconds(DEL+i/100);
//  }
//  digitalWrite(EN, HIGH);
//  dir=!dir;


  digitalWrite(DIR_x,dir);
  digitalWrite(DIR_y,dir);
  for(int i=200; i>15; i*=.99){
    for(int j=0; j<50; j++){
      digitalWrite(STP_x, HIGH);
      digitalWrite(STP_y, HIGH);
      delayMicroseconds(i);
      digitalWrite(STP_x, LOW);
      digitalWrite(STP_y, LOW);
      delayMicroseconds(i);
    }
  }
  for(int i=80; i<200; i+=1){
    for(int j=0; j<50; j++){
      digitalWrite(STP_x, HIGH);
      digitalWrite(STP_y, HIGH);
      delayMicroseconds(i);
      digitalWrite(STP_x, LOW);
      digitalWrite(STP_y, LOW);
      delayMicroseconds(i);
    }
  }
  dir=!dir;
  delay(1000);
}