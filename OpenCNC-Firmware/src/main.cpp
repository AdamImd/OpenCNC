#include <Arduino.h>
#include "StepperDriver.h"

StepperDriver stepper_x;
StepperDriver stepper_y;

void setup() {
    stepper_x = StepperDriver(21, 22, 23);
    stepper_y = StepperDriver(18, 19, 20);
}

int main(){
    
}