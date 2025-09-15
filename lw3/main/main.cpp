#include <Arduino.h>

#define analogPin 0
#define ledPin 3

int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  value = analogRead(analogPin);
  value = map(value, 0, 1023, 0, 255);
  value = constrain(value, 0, 255);
  Serial.println(value);
  analogWrite(ledPin, value);
}
