#include <Arduino.h>
#include "StepperDriver.h"
#include "LimitSwitch.h"
#include "LinearAxis.h"

StepperDriver* stepper_x;
StepperDriver* stepper_y;

LimitSwitch* limit_x;

LinearAxis* linear_x;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  stepper_x = new StepperDriver(21, 22, 23);
  stepper_y = new StepperDriver(18, 19, 20);

  limit_x = new LimitSwitch(16);

  linear_x = new LinearAxis(stepper_x, limit_x);

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

  linear_x ->zero();
}

void loop(){

}
