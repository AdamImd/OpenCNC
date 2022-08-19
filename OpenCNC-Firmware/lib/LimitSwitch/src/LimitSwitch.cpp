#include "LimitSwitch.h"
#include "Arduino.h"
#include <stdint.h>

LimitSwitch::LimitSwitch(uint8_t input_pin) {
    pin = input_pin;
    pinMode(pin, INPUT_PULLUP);
}

uint8_t LimitSwitch::is_closed() {
    return !(digitalRead(pin));
}