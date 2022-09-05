#include <Arduino.h>
#include "StepperDriver.h"
#include "LimitSwitch.h"
#include "LinearAxis.h"

StepperDriver* stepper_x;
StepperDriver* stepper_y;

LimitSwitch* limit_x;
LimitSwitch* limit_y;

LinearAxis* linear_x;
LinearAxis* linear_y;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("Ready");
  for(int i = 0; i < 5; i++){
    Serial.println("("+ String(i) + ")");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  Serial.println("Armed");

  stepper_x = new StepperDriver(21, 22, 23);
  stepper_y = new StepperDriver(18, 19, 20);

  limit_x = new LimitSwitch(16);
  limit_y = new LimitSwitch(15);

  linear_x = new LinearAxis(stepper_x, limit_x);
  linear_y = new LinearAxis(stepper_y, limit_y);

  stepper_x->set_enabled(1);
  stepper_y->set_enabled(1);
  stepper_x->set_direction_invert(1);
  stepper_y->set_direction_invert(1);
  
  
  linear_x ->zero();
  linear_y ->zero();
  
  linear_x ->move_config(20000, 15000);
  linear_x ->move_begin();
  linear_y ->move_config(20000, 10000);
  linear_y ->move_begin();
  while(!linear_x ->move_complete() || !linear_y ->move_complete());
  Serial.println("Done");
}

void loop(){

}
