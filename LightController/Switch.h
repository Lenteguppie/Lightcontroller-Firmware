#ifndef SWITCH_H
#define SWITCH_H

#include <Arduino.h>

#define StateChangeCallback void (*_callback)(int state)


class Switch{
    public:
        Switch(String name);
        long lastStateChange;
        bool stateChanged;  
        bool sync;
        int state = -1;

        void setCallback(StateChangeCallback);
        
        void attach(int pin, bool debug = false);
        void handle();

        String name;

    private:
        int pin;
        bool isStateChanged(int newState);
        void (* _callback)(int state);
        bool debug;
};
#endif