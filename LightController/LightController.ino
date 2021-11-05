#include <WiFi.h>
#include <ArduinoHA.h>

// Libraries
#include "Switch.h"
#include "Light.h"

//Switch definitions
Switch switch1("Badkamer Knop");
Light light1("Badkamer Lamp");


void setup(){
    Serial.begin(115200);
    delay(50); //to let the serial monitor open correctly
    Serial.println("Starting lightController v1.0...");

    //Attach Lights
    light1.attach(17);
    light1.setCallback([] (int state){
        Serial.print("Nieuwe light state: ");
        Serial.println(state);
    });

    //Attach Switches
    switch1.attach(5);
    switch1.setCallback([] (int state){
        Serial.print("Nieuwe switch state: ");
        Serial.println(state);
        light1.toggle();
    });
}

void loop(){
    switch1.handle();
    delay(1000);
}
