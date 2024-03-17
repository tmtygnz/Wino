#include <Arduino.h>

int readSoilMoistureSensor() {
    return analogRead(A0);
}