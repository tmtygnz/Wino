#include "sensor_test.hpp"
#include "state_handler.hpp"
#include "ultsens.hpp"
#include "welay.hpp"
#include <Arduino.h>
#include <Wire.h>
#include "soisens.hpp"

int phase = ANIKAPhases::core_setup;

ultsens frontal(D2, D3);
ultsens lateralLeft(D10, D11);
ultsens lateralRight(D4, D5);

void setup() {
    Wire.begin(8);

    Serial.begin(115200);
    while (!Serial);
    Serial.println("Running at wire 8. Baud rate 115200");

    pinMode(D2, INPUT);
    pinMode(D3, OUTPUT);
    pinMode(D10, INPUT);
    pinMode(D11, OUTPUT);
    pinMode(D4, INPUT);
    pinMode(D5, OUTPUT);

    SetupWifi();
    TestSensors();
}

void loop() {
}