#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>

#define StateChangeCallback void (*_callback)(int state)

class Light{
    public:
        Light(String name);
        long lastStateChange;
        bool stateChanged;  
        int state = -1;

        void setCallback(StateChangeCallback);
        void toggle();
        void attach(int pin, bool debug = false);

        String name;

    private:
        int pin;
        void (* _callback)(int state);
        bool debug;
};
#endif