#include <stdint.h>
#include "LinearAxis.h"
#include "Marlin.h"

MarlinDriver::MarlinDriver() {
    ring_bufer = (Command**)malloc(ring_buffer_size*sizeof(Command*));
    ring_end = ring_start = 0;
    
}