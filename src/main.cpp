#include "sensor_test.hpp"
#include "state_handler.hpp"
#include "ultsens.hpp"
#include "welay.hpp"
#include <Arduino.h>
#include <Wire.h>

int phase = ANIKAPhases::core_setup;

void setup() {
    Wire.begin(8);

    Serial.begin(115200);
    while (!Serial);
    Serial.println("Running at wire 8. Baud rate 115200");

    pinMode(D2, INPUT);
    pinMode(D3, OUTPUT);
    pinMode(D6, INPUT);
    pinMode(D7, OUTPUT);
    pinMode(D4, INPUT);
    pinMode(D5, OUTPUT);

    SetupWifi();
    TestSensors();
}

void loop() {}
