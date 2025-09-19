#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#define resistorPin 0

// Arduino: SDA – A4, SCL – A5
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(resistorPin, INPUT);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print("%");

  Serial.begin(9600);
}

int value = 0;
void loop() {
  value = analogRead(resistorPin);
  value = map(value, 0, 1023, 0, 100);
  lcd.setCursor(7, 1);
  lcd.print(String(value) + " %");
  Serial.println(String(value) + " %");  // читаем и выводим
  delay(50);
}
