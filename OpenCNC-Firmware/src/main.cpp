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
  
  Serial.println("Ready");
  for(int i = 0; i < 5; i++){
    Serial.println("("+ String(i) + ")");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  Serial.println("Armed");
  
  linear_x ->zero();
  linear_y ->zero();

  //delay(5000);

  const int dist = 1200;
  const int step = 10;
  const int speed = 12;
  for (int i = 0; i<dist; i++){
    linear_x ->move_config(i*step, i*speed);
    linear_x ->move_begin();
    linear_y ->move_config(i*step, i*speed);
    linear_y ->move_begin();
    while(!linear_x ->move_complete());
  }
  for (int i = dist; i>=0; i--){
    linear_x ->move_config(dist*step+(dist-i)*step, i*speed);
    linear_x ->move_begin();
    linear_y ->move_config(dist*step+(dist-i)*step, i*speed);
    linear_y ->move_begin();
    while(!linear_x ->move_complete());
  }

  linear_x ->move_config(0, 4000);
  linear_x ->move_begin();
  linear_y ->move_config(0, 4000);
  linear_y ->move_begin();
  while(!linear_x ->move_complete());
}

void loop(){

}
