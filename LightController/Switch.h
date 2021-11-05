#ifndef SWITCH_H
#define SWITCH_H


#include <Arduino.h>

class Switch{
    public:
        
        long lastStateChange;
        bool stateChanged;  
        bool sync;
        int state = -1;
        
        void attach(int pin, bool debug = false);
        void handle();
    
    private:
        int pin;
        bool isStateChanged(int newState);
        String name;
        bool debug;
};
#endif