#include <LiquidCrystal_I2C.h>

#define trigPin 5
#define echoPin 7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");

  Serial.begin(9600);
}

void loop() {
  float distance = getDistanceSM();
  Serial.println("Distance: " + String(distance) + " sm.");
  lcd.setCursor(8, 1);
  lcd.print(String(distance) + " sm.");
  delay(50);
}

float getDistanceSM() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  uint32_t duration = pulseIn(echoPin, HIGH);
  return duration / 58.2;
}