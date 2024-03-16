#include <Arduino.h>
#include <SoftwareSerial.h>

const int rxPin = 3;
const int txPin = 4;

SoftwareSerial communicationSerial(rxPin, txPin);

void setup() {
    // set serial communication stuffs
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);

    Serial.begin(115200);

    while (!Serial);
    Serial.println("Initializing communication serial");

    communicationSerial.begin(14400);
    Serial.println("Serial communication initalized");
}

void loop() {
    communicationSerial.println("is this data sent?");
    Serial.println("I have sent the data");
    delay(1000);
}