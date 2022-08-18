#ifndef def_StepperDriver_H
#define def_StepperDriver_H

class StepperDriver {
private:
    unsigned short pin_direction;
    unsigned short pin_enable;
    unsigned short pin_step;
    long position;
    bool direction;
    bool enable;
public:
    StepperDriver(unsigned short direction, unsigned short enable, unsigned short step);
};

// digitalWrite(STP_y, HIGH);
// delayMicroseconds(del);
// pinMode(STP_y, OUTPUT);


#endif 