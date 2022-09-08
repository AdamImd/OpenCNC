#ifndef def_GCodeParser_H
#define def_GCodeParser_H

#include <stdint.h>

class GCodeReader {
    private: 
    public:
        virtual char* readLine();
        virtual char** readLines(uint8_t lines); 
        
};

#endif
