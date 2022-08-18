#ifndef def_StepperDriver
#define def_StepperDriver

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