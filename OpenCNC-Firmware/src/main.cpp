#include <Arduino.h>

const int EN=5;
const int DIR=4;
const int STP=16;

void setup() {
  // put your setup code here, to run once:
  pinMode(EN, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(STP, OUTPUT);
  digitalWrite(EN, LOW);
  digitalWrite(DIR, LOW);
  digitalWrite(STP, LOW);
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


  digitalWrite(DIR,dir);
  for(int i=200; i>15; i*=.99){
    for(int j=0; j<50; j++){
      digitalWrite(STP, HIGH);
      delayMicroseconds(i);
      digitalWrite(STP, LOW);
      delayMicroseconds(i);
    }
  }
  for(int i=80; i<200; i+=1){
    for(int j=0; j<50; j++){
      digitalWrite(STP, HIGH);
      delayMicroseconds(i);
      digitalWrite(STP, LOW);
      delayMicroseconds(i);
    }
  }
  dir=!dir;
  delay(1000);
}