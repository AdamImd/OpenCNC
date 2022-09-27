#include "SerialReader.h"
#include "Arduino.h"
char* SerialReader::readBytes(char* buf, uint16_t size) {
    Serial.readBytes(buf, size);
}

void SerialReader::open() {
    Serial.begin(9600);
}

void SerialReader::open(uint16_t baud) {
    Serial.begin(baud);
}

void SerialReader::close() {
    Serial.end();
}
