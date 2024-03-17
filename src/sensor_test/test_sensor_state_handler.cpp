#include "soisens.hpp"
#include "ultsens.hpp"

void soilMoistureSensorTest() {
    for (int i = 0; i != 15; i++) {
        int data = readSoilMoistureSensor();
        Serial.println(data);
    }
}

void ultrasonicSensorTest() {
    ultsens frontal(D2, D3);
    ultsens lateralLeft(D10, D11);
    ultsens lateralRight(D4, D5);
    for (int i = 0; i < 15; i++) {
        float fDist = frontal.dist();
        float lRDist = lateralRight.dist();
        float lLDist = lateralLeft.dist();
        Serial.println("F: " + String(fDist) + " LR: " + String(lRDist) +
                       " LL: " + String(lLDist));
    }
}

void TestSensors() {
    ultrasonicSensorTest();
    soilMoistureSensorTest();
}
