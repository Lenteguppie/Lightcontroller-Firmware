#include "Switch.h"

bool Switch::isStateChanged(int newState)
{
    return (newState != state);
}

void Switch::attach(int pin, bool debug)
{
    this->pin = pin;
    pinMode(this->pin, INPUT_PULLUP);

    Serial.print("A new switch is attached to GPIO: ");
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

        lastStateChange = millis();
        stateChanged = false;
        sync = true;
    }
}