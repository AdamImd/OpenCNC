#include "StepperDriver.h"
#include "Arduino.h"
#include <stdint.h>

StepperDriver::StepperDriver(uint8_t enable, uint8_t direction, uint8_t step) {
    pin_enable = enable;
    pin_direction = direction;
    pin_step = step;

    position = 0L;
    step_direction = 0;
    enabled = 0;
    step_direction_inverted = 0;
    step_complete = 1;

    pinMode(pin_enable, OUTPUT);
    pinMode(pin_direction, OUTPUT);
    pinMode(pin_step, OUTPUT);

    digitalWrite(pin_enable, 0);
    digitalWrite(pin_direction, 0);
    digitalWrite(pin_step, 0);
}

uint8_t StepperDriver::set_enabled(uint8_t enable){
    uint8_t tmp = enabled;
    enabled = enable;
    digitalWrite(pin_enable, !enabled);
    delayNanoseconds(pulse_length_ns);            //uint32_t steps_mm;    //uint32_t steps_mm;
    return tmp;
}

uint8_t StepperDriver::get_enabled(){
    return enabled;
}

uint8_t StepperDriver::set_direction(uint8_t dir){
    uint8_t tmp = step_direction;
    step_direction = (step_direction_inverted ?  !dir : dir); 
    digitalWrite(pin_direction, step_direction);
    return tmp;
}

uint8_t StepperDriver::get_direction(){
    return step_direction;
}

uint8_t StepperDriver::set_direction_invert(uint8_t invert){
    uint8_t tmp = step_direction_inverted;
    step_direction_inverted = invert;
    return tmp;
}

uint8_t StepperDriver::get_direction_invert(){
    return step_direction_inverted;
}

uint8_t StepperDriver::get_step_complete(){
    return step_complete;
}

int32_t StepperDriver::set_position(int32_t pos){
    int32_t tmp = position;
    position = pos;
    return tmp;
}

int32_t StepperDriver::get_position(){
    return position;
}

int32_t StepperDriver::step(){
    step_complete = !step_complete;
    if(!step_complete){
        digitalWrite(pin_step, 1);
        return position;
    } else {
        digitalWrite(pin_step, 0);
        return (step_direction ? --position : ++position); // ?
    }
}

int32_t StepperDriver::step(uint8_t direction){
    set_direction(direction);
    return step();
}
