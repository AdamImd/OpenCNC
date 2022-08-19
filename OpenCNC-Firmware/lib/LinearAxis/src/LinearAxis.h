#ifndef def_LinearAxis_H
#define def_LinearAxis_H

#include <stdint.h>
#include "StepperDriver.h"

class LinearAxis {
    private: 
        IntervalTimer timer;
        StepperDriver* driver;
    public:
        LinearAxis(StepperDriver* axis);
};

#endif
