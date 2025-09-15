#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    pinMode(A0, OUTPUT);
}

void loop() {
    digitalWrite(A0, LOW);
    delay(1);
    Serial.println(analogRead(A0));
    delay(500);

    digitalWrite(A0, HIGH);
    delay(1);
    Serial.println(analogRead(A0));
    delay(500);
}