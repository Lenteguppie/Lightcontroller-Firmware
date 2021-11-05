#include "Switch.h"

Switch::Switch(String name){
    this->name = name;
}

void Switch::setCallback(StateChangeCallback){
    this->_callback = _callback;
}

bool Switch::isStateChanged(int newState)
{
    return (newState != state);
}

void Switch::attach(int pin, bool debug)
{
    this->pin = pin;
    pinMode(this->pin, INPUT_PULLUP);

    Serial.print("A new switch called: \"");
    Serial.print(name);
    Serial.print("\" is attached to GPIO: ");
    Serial.println(this->pin);
    //attach interrupt to pin
    this->debug = debug;
}

void Switch::handle()
{
    int newState = digitalRead(this->pin);
    stateChanged = this->isStateChanged(newState);

    // Debug prints
    // Serial.print(newState);
    // Serial.print("\t");
    // Serial.print(this->state);
    // Serial.print("\t");
    // Serial.print(stateChanged);
    // Serial.println("");

    if (stateChanged)
    {
        state = newState;

        if(debug){
            Serial.print(F("The state changed to: "));
            if(!state){
                Serial.println(F("ON."));
            }else if(state){
                Serial.println(F("OFF."));
            }else{
                Serial.println(F("UNKNOWN."));
            }
            
        }
        
        _callback(state);
        lastStateChange = millis();
        stateChanged = false;
        sync = true;
    }
}