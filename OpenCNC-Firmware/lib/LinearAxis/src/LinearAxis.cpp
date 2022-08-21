#include "LinearAxis.h"
#include "LimitSwitch.h"
#include "Arduino.h"
#include <stdint.h>

LinearAxis::LinearAxis(StepperDriver* axis, LimitSwitch* sw) {
    driver = axis;
    limit = sw;
    status = 0;
    steps_mm = 1064;
    drivers_size = 4;
    drivers = (drivers) ? drivers : (StepperDriver**)malloc(sizeof(StepperDriver*) * drivers_size);
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

    if (!drivers) return 0;
    int8_t callback = -1;
    for (int i = 0; i<drivers_size; i++)
        if (!drivers[i])
            callback = i;
    if (callback < 1) return 0;
    drivers[callback] = driver;
    void (*funct)();
    switch (callback) {
    case 0:
        funct = callback_fun_0;
    case 1:
        funct = callback_fun_1;
    case 2:
        funct = callback_fun_2;
    case 3:
        funct = callback_fun_3;
    }
    if (!timer.begin(funct, step_time))
        return 0;

    status = 1; 
    return 1;
}

void LinearAxis::callback_fun_0() {
    drivers[0]->step();
}

void LinearAxis::callback_fun_1() {
    drivers[1]->step();
}

void LinearAxis::callback_fun_2() {
    drivers[2]->step();
}

void LinearAxis::callback_fun_3() {
    drivers[3]->step();
}