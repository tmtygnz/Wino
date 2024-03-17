#pragma once
#include <Arduino.h>

class ultsens {
public:
    ultsens(int echo, int trig);
    float dist() const;
private:
    int echo;
    int trig;
};