#include <Arduino.h>

#define ledPin 9

int light;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        light = Serial.parseInt();
    }

    analogWrite(ledPin, light);
}