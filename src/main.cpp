#include <Wire.h>
#include <Arduino.h>
#include "state_handler.hpp"
#include "welay.hpp"

int phase = ANIKAPhases::setup;

void setup() {
    Wire.begin(8);

    Serial.begin(115200);
    while (!Serial);
    Serial.println("Running at wire 8. Baud rate 115200");

    SetupWifi();
}

void loop() {
}
