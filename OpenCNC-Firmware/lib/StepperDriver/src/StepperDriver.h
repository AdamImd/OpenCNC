#ifndef def_StepperDriver_H
#define def_StepperDriver_H

class StepperDriver {
private:
    uint8_t pin_direction;
    uint8_t pin_enable;
    uint8_t pin_step;
    long position;
    bool enabled;
    bool step_direction;
    
    const uint32_t pulse_length_us = 100;

public:
    StepperDriver(uint8_t enable, uint8_t direction, uint8_t step);
    bool set_enabled(bool enable);
    bool get_enabled();
    bool set_direction(bool dir);
    bool get_direction();
    long set_position(long pos);
    long get_position();
    long step();
    long step(bool direction);


};

#endif 