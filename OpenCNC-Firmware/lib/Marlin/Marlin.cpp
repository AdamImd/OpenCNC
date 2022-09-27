#include <stdint.h>
#include "LinearAxis.h"
#include "Marlin.h"

MarlinDriver::MarlinDriver(GCodeReader* g_parser, LinearAxis* x, LinearAxis* y, LinearAxis* z) {
    ring_buffer_size = 1024;
    ring_buffer = (Command*)malloc(ring_buffer_size*sizeof(Command));
    ring_end = ring_start = 0;

    x_axis = x;
    y_axis = y;
    z_axis = z;

    parser = g_parser;
    
}

void MarlinDriver::run() {
    if(state == 0){
        
    }
}