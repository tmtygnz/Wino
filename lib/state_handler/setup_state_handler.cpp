#include <Arduino.h>

void SetupPins() {
    // 3,4
    // 6,7
    // 8,9
    pinMode(3, INPUT);
    pinMode(6, INPUT);
    pinMode(8, INPUT);

    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
}