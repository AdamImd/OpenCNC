#include "StepperDriver.h"
#include "Arduino.h"

StepperDriver::StepperDriver(uint8_t enable, uint8_t direction, uint8_t step) {
    pin_enable = enable;
    pin_direction = direction;
    pin_step = step;

    position = 0L;
    step_direction = 0;
    enabled = 0;

    pinMode(pin_enable, OUTPUT);
    pinMode(pin_direction, OUTPUT);
    pinMode(pin_step, OUTPUT);

    digitalWrite(pin_enable, 0);
    digitalWrite(pin_direction, 0);
    digitalWrite(pin_step, 0);
}

bool StepperDriver::set_enabled(bool enable){
    bool tmp = enabled;
    enabled = enable;
    digitalWrite(pin_enable, enabled);
    delayMicroseconds(pulse_length_us);
    return tmp;
}

bool StepperDriver::get_enabled(){
    return enabled;
}

bool StepperDriver::set_direction(bool dir){
    bool tmp = step_direction;
    step_direction = dir;
    digitalWrite(pin_step, step_direction);
    delayMicroseconds(pulse_length_us);
    return tmp;
}

bool StepperDriver::get_direction(){
    return step_direction;
}

long StepperDriver::set_position(long pos){
    position = pos;
}

long StepperDriver::get_position(){
    return position;
}

long StepperDriver::step(){
    digitalWrite(pin_step, 1);
    delayMicroseconds(pulse_length_us);
    digitalWrite(pin_step, 0);
    delayMicroseconds(pulse_length_us);
    return (step_direction ? ++position : --position);
}

long StepperDriver::step(bool direction){
    set_direction(direction);
    return step();
}