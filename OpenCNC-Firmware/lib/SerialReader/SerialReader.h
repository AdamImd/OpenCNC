#ifndef def_SerialReader_H
#define def_SerialReader_H

#include <stdint.h>
#include "GCodeReader.h"

class SerialReader : public GCodeStream {
    private: 

    public:
        char* readBytes(char* buf, uint16_t size) override;
        uint8_t isOpen() override;
        void close() override;
        void open() override;
        void open(uint16_t baud);
        
};

#endif
