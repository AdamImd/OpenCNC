#ifndef def_GCodeReader_H
#define def_GCodeReader_H

#include <stdint.h>

class GCodeStream {
    public:
        virtual uint8_t isOpen();
        virtual void open();
        virtual void close();
        virtual GCodeRawCommand* readCommand();
};

class Command {
    public:
        virtual void* init(const char* input_data);
        virtual bool* run();
};

struct GCodeRawCommand // Holds raw data from GCodeStream
{
    char g_type;
    uint16_t g_num;
    char* data;
};

struct GCodeCommandEnum {
    char g_type;
    uint16_t g_num;
    Command* command;
};

GCodeRawCommand* string_to_GCodeRawCommand(const char* input_data){
    GCodeRawCommand* command = (GCodeRawCommand*)malloc(sizeof(GCodeRawCommand));
    command->g_type = input_data[0];
    command->g_num = (input_data[1] - '0') * 10 + (input_data[2] - '0');
    command->data = (char*)malloc(sizeof(char) * (strlen(input_data) - 3));
    for(uint16_t i = 3; i < strlen(input_data); i++){
        command->data[i - 3] = input_data[i];
    }
    return command;
}

#endif
