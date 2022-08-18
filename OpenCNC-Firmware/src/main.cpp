#include <Arduino.h>
#include "StepperDriver.h"

StepperDriver *stepper_x;
StepperDriver *stepper_y;

void setup() {
    stepper_x = new StepperDriver(21, 22, 23);
    stepper_y = new StepperDriver(18, 19, 20);

    stepper_x->set_enabled(1);
    stepper_y->set_enabled(1);
    
}

bool dir = 1;
int main(){
    for(int i = 0; i<6000; i++){
        stepper_x->step(dir);
        stepper_y->step(dir);
        delayMicroseconds(200);
    }
    dir = !dir;
}