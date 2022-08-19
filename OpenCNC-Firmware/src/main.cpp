#include <Arduino.h>
#include "StepperDriver.h"

StepperDriver *stepper_x;
StepperDriver *stepper_y;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  

  stepper_x = new StepperDriver(21, 22, 23);
  stepper_y = new StepperDriver(18, 19, 20);

  stepper_x->set_enabled(1);
  stepper_y->set_enabled(1);
  stepper_x->set_direction_invert(1);
  stepper_y->set_direction_invert(1);
  
  Serial.println("Ready");
  for(int i =0; i<5; i++){
    Serial.println("("+ String(i) + ")");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  Serial.println("Armed");
}

bool dir = 1;
void loop(){
  for(int i = 0; i<20000; i++){
      stepper_x->step(dir);
      stepper_y->step(dir);
      delayMicroseconds(100);
  }
  dir = !dir;
  for(int i = 0; i<20000; i++){
      stepper_x->step(dir);
      stepper_y->step(dir);
      delayMicroseconds(100);
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  dir = !dir;
}