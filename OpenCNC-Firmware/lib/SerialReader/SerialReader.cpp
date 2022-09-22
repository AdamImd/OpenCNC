#include "SerialReader.h"
#include "Arduino.h"
void* SerialReader::process() {
    Serial.readString();
}
