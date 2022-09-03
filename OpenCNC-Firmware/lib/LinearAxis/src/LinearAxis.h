#ifndef def_LinearAxis_H
#define def_LinearAxis_H

#include <stdint.h>
#include "StepperDriver.h"
#include "LimitSwitch.h"

class LinearAxis {
    private: 
        IntervalTimer timer;
        StepperDriver* driver;
        LimitSwitch* limit;
        uint8_t status;
        int32_t target;
        //uint32_t steps_mm;
        int8_t callback;
        void step();
        static void callback_fun_0();
        static void callback_fun_1();
        static void callback_fun_2();
        static void callback_fun_3();
        static int8_t axis_size;
        static LinearAxis** axis_arr;
    public:
        LinearAxis(StepperDriver* axis, LimitSwitch* sw);
        uint8_t zero();
        uint8_t move_config(int32_t target, float speed);
        uint8_t move_begin();
        uint8_t move_complete();
};

#endif
