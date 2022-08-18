#ifndef def_StepperDriver_H
#define def_StepperDriver_H

#include <stdint.h>

class StepperDriver {
private:
    uint8_t pin_direction;
    uint8_t pin_enable;
    uint8_t pin_step;
    uint8_t enabled;
    uint8_t step_direction;
    int32_t position;
    
    const uint32_t pulse_length_us = 100;

public:
    StepperDriver(uint8_t enable, uint8_t direction, uint8_t step);
    uint8_t set_enabled(uint8_t enable);
    uint8_t get_enabled();
    uint8_t set_direction(uint8_t dir);
    uint8_t get_direction();
    int32_t set_position(int32_t pos);
    int32_t get_position();
    int32_t step();
    int32_t step(uint8_t direction);


};

#endif 