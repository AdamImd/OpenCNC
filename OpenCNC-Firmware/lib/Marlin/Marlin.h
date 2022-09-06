#ifndef def_MarlinDriver_H
#define def_MarlinDriver_H

#include <stdint.h>
#include "LinearAxis.h"

struct Command
{
    uint16_t command_num;
    void* data;
};

class MarlinDriver {
    private: 
        Command** ring_bufer;
        uint16_t ring_start;
        uint16_t ring_end; 
        uint16_t ring_buffer_size;
        
    public:
        MarlinDriver();
        void G4(uint32_t del); // Dwell
        

};


#endif
