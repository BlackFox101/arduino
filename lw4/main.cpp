#include <Arduino.h>

#define trigPin 12
#define echoPin 11

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

float getDistanceSM() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  const uint32_t duration = pulseIn(echoPin, HIGH);
  return duration / 58.2;
}

void loop() {
  const float distance = getDistanceSM();
  Serial.println(distance);
  delay(50);
}
