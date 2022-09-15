#ifndef def_GCodeReader_H
#define def_GCodeReader_H

#include <stdint.h>

class GCodeReader {
    public:
        virtual void* process();
        virtual bool isDone();
};

#endif
