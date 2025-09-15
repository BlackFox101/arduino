#include <Arduino.h>

#define led_red 12
#define led_yellow 11
#define led_green 10

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);

  // Serial.begin(9600);
  // Serial.println("START");
}

void loop() {
  digitalWrite(led_red, 1);
  digitalWrite(led_yellow, 0);
  digitalWrite(led_green, 0);

  delay(10000);

  digitalWrite(led_yellow, 1);

  delay(1500);

  digitalWrite(led_red, 0);
  digitalWrite(led_yellow, 0);
  digitalWrite(led_green, 1);

  delay(10000);

  bool light = false;
  for (int i = 0; i < 4; i++) {
    light = !light;
    digitalWrite(led_green, light);
    delay(500);
  }

  digitalWrite(led_yellow, 1);
  digitalWrite(led_green, 0);
  delay(1000);
}
