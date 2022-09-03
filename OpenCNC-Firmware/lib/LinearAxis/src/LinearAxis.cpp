#include "LinearAxis.h"
#include "LimitSwitch.h"
#include "Arduino.h"
#include <stdint.h>

int8_t LinearAxis::axis_size;
LinearAxis** LinearAxis::axis_arr;

LinearAxis::LinearAxis(StepperDriver* axis, LimitSwitch* sw) {
    driver = axis;
    limit = sw;
    status = 0;
    //steps_mm = 1064;
    callback = -1;
    axis_size = 4;
    axis_arr = (axis_arr) ? axis_arr : (LinearAxis**)calloc(axis_size, sizeof(LinearAxis*));
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

uint8_t LinearAxis::move_config(int32_t target_pos, float steps_per_second) {
    if (status == 2) return 0;

    target = target_pos;
    float step_time = (((1 / steps_per_second) * 1000000) /2);

    if (!axis_arr) return 0;
    if (callback == -1){
        for (int i = 0; i<axis_size; i++)
            if (!axis_arr[i])
                callback = i;
        if (callback < 1) return 0;
        axis_arr[callback] = this;
    }
    void (*funct)();
    switch (callback) {
    case 0:
        funct = callback_fun_0;
    case 1:
        funct = callback_fun_1;
    case 2:
        funct = callback_fun_2;        //uint32_t steps_mm;
    case 3:
        funct = callback_fun_3;
    }
    if (!timer.begin(funct, step_time))
        return 0;        //uint32_t steps_mm;

    status = 1; 
    return 1;
}

uint8_t LinearAxis::move_begin(){
    return (status != 1) ? status : status = 2;
}

uint8_t LinearAxis::move_complete(){
    return status == 0;
}

void LinearAxis::step(){
    if (!driver->get_enabled()) return;
    if (status != 2) return;
    if (!driver->get_step_complete()) {
        int32_t diff = target - driver->get_position();
        if (diff == 0){
            status = 0;
            timer.end();

            return;
        }
        //if (driver->get_direction() == (diff > 0))
            driver->set_direction((diff > 0));
    }
    driver->step();
}


void LinearAxis::callback_fun_0() {
    axis_arr[0]->step();
}
void LinearAxis::callback_fun_1() {
    axis_arr[1]->step();
}
void LinearAxis::callback_fun_2() {
    axis_arr[2]->step();
}
void LinearAxis::callback_fun_3() {
    axis_arr[3]->step();
}