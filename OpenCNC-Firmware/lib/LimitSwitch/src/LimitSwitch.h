#ifndef def_LimitSwitch_H
#define def_LimitSwitch_H

#include "Arduino.h"
#include <stdint.h>
#include "LimitSwitch.h"

class LimitSwitch {
    private: 
        uint8_t pin;
    public:
        LimitSwitch(uint8_t input_pin);
        uint8_t is_closed();
};

#endif
