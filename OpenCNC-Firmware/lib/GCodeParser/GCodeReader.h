#ifndef def_GCodeReader_H
#define def_GCodeReader_H

#include <stdint.h>

class GCodeReader {
    public:
        virtual char* readBytes(char* buf, uint16_t size);
        virtual uint8_t isOpen();
        virtual void open();
        virtual void close();
};

#endif
