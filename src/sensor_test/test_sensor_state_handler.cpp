#include "ultsens.hpp"

void soilMoistureSensorTest() {}

void ultrasonicSensorTest() {
    ultsens frontal(D2, D3);
    ultsens lateralLeft(D6, D7);
    ultsens lateralRight(D4,D5);
    float fDist = frontal.dist();
    Serial.println("Frontal Read Distance: " + String(fDist));

    float lRDist = lateralRight.dist();
    Serial.println("Lateral Right Read Distance: " + String(lRDist));

    float lLDist = lateralLeft.dist();
    Serial.println("Lateral Left Read Distance: " + String(lLDist));
}

void TestSensors() { ultrasonicSensorTest(); }
