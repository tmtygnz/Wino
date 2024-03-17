#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "HUAWEI=2.4g-S49g";
const char* ssidPassword = "UjcXk4Ug";

void SetupWifi() {
    WiFi.begin(ssid, ssidPassword);
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to the internet");
    }
    Serial.print("Connected, running at ");
    Serial.print(WiFi.localIP());
}

void SendToServer() {
    HTTPClient client;
    // TODO: Implement relay code;
}
