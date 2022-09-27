#ifndef def_SerialReader_H
#define def_SerialReader_H

#include <stdint.h>
#include "GCodeReader.h"

class SerialReader {
    private: 

    public:
        char* readBytes(char* buf, uint16_t size);
        uint8_t isOpen();
        void open();
        void open(uint16_t baud);
        void close();
        
};

#endif
