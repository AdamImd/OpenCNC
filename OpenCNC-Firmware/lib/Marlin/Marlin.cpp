#include <stdint.h>
#include "LinearAxis.h"
#include "Marlin.h"

MarlinDriver::MarlinDriver(GCodeReader* g_parser, LinearAxis* x, LinearAxis* y, LinearAxis* z) {
    ring_bufer = (Command**)malloc(ring_buffer_size*sizeof(Command*));
    ring_end = ring_start = 0;
    
}