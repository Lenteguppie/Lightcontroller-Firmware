#include <WiFiManager.h>

// Libraries
#include "Switch.h"
#include "Light.h"

WiFiManager wifiManager;

//Switch definitions
Switch switch1("Badkamer Knop");
Light light1("Badkamer Lamp");


void setup(){
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP    
    
    Serial.begin(115200);
    delay(50); //to let the serial monitor open correctly
    
    Serial.println("Starting lightController v1.1...");

    //reset settings - wipe credentials for testing
    // wifiManager.resetSettings();

    wifiManager.setConfigPortalBlocking(false);

    //automatically connect using saved credentials if they exist
    //If connection fails it starts an access point with the specified name
    if(wifiManager.autoConnect("LightControl")){
        Serial.println("connected...yeey :)");
    }
    else {
        Serial.println("Unable to connect to wifi. Config portal is running...");
    }

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

    wifiManager.process();
    delay(1000);
}
