#include "Light.h"

Light::Light(String name)
{
    this->name = name;
}

void Light::setCallback(StateChangeCallback)
{
    this->_callback = _callback;
}

void Light::attach(int pin, bool debug)
{
    this->pin = pin;
    pinMode(this->pin, OUTPUT);

    digitalWrite(this->pin, LOW); //Turn off the lights by default
    state = 1;

    //attach interrupt to pin
    this->debug = debug;

    // Log the newly added lamp.
    Serial.print("A new switch called: \"");
    Serial.print(name);
    Serial.print("\" is attached to GPIO: ");
    Serial.println(this->pin);
}

void Light::toggle()
{
    if (state == 0)
    {
        state = 1;
        digitalWrite(this->pin, LOW);
    }
    else
    {
        state = 0;
        digitalWrite(this->pin, HIGH);
    }

    this->_callback(state);
}
