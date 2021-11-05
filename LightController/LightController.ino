#include <WiFi.h>
#include <ArduinoHA.h>

// Libraries
#include "Switch.h"

//Switch definitions
Switch switch1("Badkamer Knop");


void setup(){
    Serial.begin(115200);
    delay(50); //to let the serial monitor open correctly
    Serial.println("Starting lightController v1.0...");
    switch1.attach(5);
    switch1.setCallback([] (int state){
        Serial.print("Nieuwe state: ");
        Serial.println(state);
    });
}

void loop(){
    switch1.handle();
    delay(1000);
}
