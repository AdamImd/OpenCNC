#ifndef def_MarlinDriver_H
#define def_MarlinDriver_H

#include <stdint.h>
#include "LinearAxis.h"
#include "GCodeParser.h"

struct Command
{
    uint16_t command_num;
    void* data;
};

class MarlinDriver {
    private: 
        GCodeReader* parser;
        LinearAxis* x_axis;
        LinearAxis* y_axis;
        LinearAxis* z_axis;
        Command** ring_bufer;
        uint16_t ring_start;
        uint16_t ring_end; 
        uint16_t ring_buffer_size;
        
        void G4(uint32_t del); // Dwell

        void fill_buffer();
    public:
        MarlinDriver(GCodeReader* g_parser, LinearAxis* x, LinearAxis* y, LinearAxis* z);
        void set_steps_per_mm(uint16_t x, uint16_t y, uint16_t z);
        
        void run();

};


#endif
