#include <stdint.h>
#include "LinearAxis.h"
#include "Marlin.h"

MarlinDriver::MarlinDriver(LinearAxis* x, LinearAxis* y, LinearAxis* z) {
    ring_buffer_size = 1024;
    command_buffer = (GCodeRawCommand*)malloc(ring_buffer_size*sizeof(GCodeRawCommand));
    ring_end = ring_start = 0;

    x_axis = x;
    y_axis = y;
    z_axis = z;
}

bool MarlinDriver::load_stream(GCodeStream* stream){
    // TODO: this.stop();
    g_stream = stream;
    return !stream->isOpen()
}

bool MarlinDriver::run() {`
    if(current_command >= 0){ // If there is an active command
        current_command = command_list[current_command].command->run() ? current_command : -1; // Run the command
    } else { // If there is no active command
        GCodeRawCommand* raw_command = get_command(); // Get command from ring buffer
        if(raw_command == NULL) return false; // If there is no command in the ring buffer
        // TODO: Log empty buffer
        for(uint16_t i = 0; i < command_list_size; i++){ // For each command in the command list
            if(raw_command->g_type == command_list[i].g_type && raw_command->g_num == command_list[i].g_num){ 
                 current_command = i; // Set current command to the command in the command list
                 command_list[current_command].command->init(raw_command->data); // Initialize the command
                 return true;
            }
        }
    }
    return false;
    // Todo: Log command not found
}

GCodeRawCommand* MarlinDriver::get_command(){ // Get command from ring buffer
    if(ring_start == ring_end) return NULL;
    GCodeRawCommand* command = &command_buffer[ring_start];
    ring_start = (ring_start + 1) % ring_buffer_size;
    return command;
}

bool MarlinDriver::insert_command(GCodeRawCommand command){ // Insert command into ring buffer
    if(ring_start == ((ring_end -1 + ring_buffer_size) % ring_buffer_size)) return false; // If buffer is full 
    command_buffer[ring_end] = command;
    ring_end = (ring_end + 1) % ring_buffer_size;
    return true;
}
