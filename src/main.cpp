#include "sensor_test.hpp"
#include "soisens.hpp"
#include "state_handler.hpp"
#include "ultsens.hpp"
#include "welay.hpp"
#include <Arduino.h>
#include <Wire.h>

int phase = ANIKAPhases::core_setup;
float tooCloseofaDistance = 9;

ultsens frontalSensor(D2, D8);
ultsens lateralLeft(D10, D11);
ultsens lateralRight(D12, D13);


void sendPhase() {
    Wire.beginTransmission(8);
    Wire.write(phase);
    Wire.endTransmission();
}

void setup() {
    Wire.begin();

    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("Running at wire 8. Baud rate 115200");

    pinMode(D2, INPUT);
    pinMode(D8, OUTPUT);
    pinMode(D10, INPUT);
    pinMode(D11, OUTPUT);
    pinMode(D12, INPUT);
    pinMode(D13, OUTPUT);

    SetupWifi();

    phase = ANIKAPhases::test_sensors;
    TestSensors();

    phase = ANIKAPhases::move;
}

void measureUCS() {
    float frontalDistance = frontalSensor.dist();
    float lateralLeftDistance = lateralLeft.dist();
    float lateralRightDistance = lateralRight.dist();

    if (frontalDistance < 9) {
        if (lateralLeftDistance > 9 &&
            lateralLeftDistance > lateralRightDistance) {
            phase = ANIKAPhases::move_left;
            sendPhase(); 
            Serial.println("Should send, looking left");
            delay(2000);
            phase = ANIKAPhases::move;
            sendPhase();
        } else if (lateralRightDistance > 9 &&
                   lateralRightDistance > lateralLeftDistance) {
            phase = ANIKAPhases::move_right;
            sendPhase();
            Serial.println("Should send, looking right");
            delay(2000);
            phase = ANIKAPhases::move;
            sendPhase();
        }
    }
}

void loop() {
    sendPhase();
    measureUCS();
}
