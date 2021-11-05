// Libraries
#include "Switch.h"

//Switch definitions
Switch switch1;


void setup(){
    Serial.begin(115200);
    delay(50); //to let the serial monitor open correctly
    Serial.println("Starting lightController v1.0...");
    switch1.attach(5, true);
}

void loop(){
    switch1.handle();
    delay(1000);
}
