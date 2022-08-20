#include "LinearAxis.h"
#include "LimitSwitch.h"
#include "Arduino.h"
#include <stdint.h>

LinearAxis::LinearAxis(StepperDriver* axis, LimitSwitch* sw) {
    driver = axis;
    limit = sw;
    status = 0;
    steps_mm = 1064;
}

uint8_t LinearAxis::zero() {
    if (!driver->get_enabled()) return 0;
    while (!limit->is_closed()){
        driver->step(0);
        delayMicroseconds(200);
    }
    driver->set_position(0);
    return 1;
}

uint8_t LinearAxis::move_config(int32_t target_pos, float speed) {
    if (!driver->get_enabled()) return 0;

    target = target_pos;
    float step_time = speed * steps_mm;
    if(!timer.begin(*(this->callback), step_time))
        return 0;

    status = 1; 
    return 1;
}