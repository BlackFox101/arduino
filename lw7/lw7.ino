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
  lcd.print("Light: ");
  // lcd.print("%");

  Serial.begin(9600);
}

int value = 0;
void loop() {
  value = analogRead(0);
  value = map(value, 0, 1023, 0, 100);
  lcd.setCursor(7, 1);
  lcd.print(String(value) + " %");
  Serial.println(String(value) + " %");  // читаем и выводим
  delay(50);
}
