#include "ultsens.hpp"
ultsens::ultsens(int echo, int trig) {
    this->echo = echo;
    this->trig = trig;
}

ultsens::~ultsens() {
    ~this->echo;
    ~this->trig;
}

/// @brief Get's distance measured by the ultrasonic sensor by sending a wave then measuring its return time then calculating it.
/// @return float, the calculated distance.
float ultsens::dist() const {
    digitalWrite(this->trig, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trig, HIGH);
    delayMicroseconds(9);
    digitalWrite(this->trig, LOW);
    noInterrupts();
    float d = pulseIn(this->echo, HIGH, 23529.4);
    interrupts();
    return d / 58.8235;
}