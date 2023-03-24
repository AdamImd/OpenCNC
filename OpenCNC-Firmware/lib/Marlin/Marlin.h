#ifndef def_MarlinDriver_H
#define def_MarlinDriver_H

#include <stdint.h>
#include "LinearAxis.h"
#include "GCodeReader.h"


class MarlinDriver {
    private: 
        GCodeStream* g_stream;
        LinearAxis* x_axis;
        LinearAxis* y_axis;
        LinearAxis* z_axis;

        GCodeRawCommand* command_buffer;
        uint16_t ring_start;
        uint16_t ring_end; 
        uint16_t ring_buffer_size;

        int16_t current_command;

        GCodeCommandEnum* command_list;
        uint16_t command_list_max_size;
        uint16_t command_list_size;
        

        
        void fill_buffer();
        GCodeRawCommand* get_command();
        bool insert_command(GCodeRawCommand command);
    public:
        MarlinDriver(LinearAxis* x, LinearAxis* y, LinearAxis* z);
        void set_steps_per_mm(uint16_t x, uint16_t y, uint16_t z);
        
        bool load_stream(GCodeStream* stream);
        bool run();

};


#endif
