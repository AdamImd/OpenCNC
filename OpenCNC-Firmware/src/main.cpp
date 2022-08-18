#include <Arduino.h>
#include "StepperDriver.h"

StepperDriver stepper_x;
StepperDriver stepper_y;

void setup() {
    stepper_x = StepperDriver(22, 21, 23);
    stepper_y = StepperDriver(19, 18, 20);
}

int main(){

}