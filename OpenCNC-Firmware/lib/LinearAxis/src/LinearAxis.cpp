#include "LinearAxis.h"
#include "Arduino.h"
#include <stdint.h>

LinearAxis::LinearAxis(StepperDriver* axis) {
    driver = axis;
    
}