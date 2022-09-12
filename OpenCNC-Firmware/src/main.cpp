#include <Arduino.h>
#include "StepperDriver.h"
#include "LimitSwitch.h"
#include "LinearAxis.h"
#include "Marlin.h"

StepperDriver* stepper_x;
StepperDriver* stepper_y;
StepperDriver* stepper_z;

LimitSwitch* limit_x;
LimitSwitch* limit_y;
LimitSwitch* limit_z;

LinearAxis* linear_x;
LinearAxis* linear_y;
LinearAxis* linear_z;

MarlinDriver* driver;

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
  stepper_y = new StepperDriver(15, 16, 17);
  stepper_z = new StepperDriver(18, 19, 20);

  limit_x = new LimitSwitch(41);
  limit_y = new LimitSwitch(40);
  limit_z = new LimitSwitch(39);

  linear_x = new LinearAxis(stepper_x, limit_x);
  linear_y = new LinearAxis(stepper_y, limit_y);
  linear_z = new LinearAxis(stepper_z, limit_z);

  //driver = new MarlinDriver();

  stepper_x->set_enabled(1);
  stepper_y->set_enabled(1);
  stepper_z->set_enabled(1);

  stepper_x->set_direction_invert(1);
  stepper_y->set_direction_invert(1);
  stepper_z->set_direction_invert(1);
  
  linear_x ->zero();
  linear_y ->zero();
  
  linear_x ->move_config(10000, 5000);
  linear_x ->move_begin();
  linear_y ->move_config(10000, 5000);
  linear_y ->move_begin();
  linear_z->move_config(10000, 30000);
  linear_z->move_begin();
  while(!linear_z ->move_complete());
  while(!linear_x ->move_complete() || !linear_y ->move_complete());

  linear_x ->move_config(5000, 5000);
  linear_x ->move_begin();
  linear_y ->move_config(5000, 5000);
  linear_y ->move_begin();
  linear_z ->move_config(0, 10000);
  linear_z ->move_begin();
  while(!linear_z->move_complete());
  while(!linear_x ->move_complete() || !linear_y ->move_complete());
  
  stepper_y->set_enabled(0);
  stepper_x->set_enabled(0);
  stepper_z->set_enabled(0);

  Serial.println("Done");
}

void loop(){

}
