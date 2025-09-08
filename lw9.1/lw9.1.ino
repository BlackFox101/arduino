#define R_PIN 10
#define G_PIN 9
#define B_PIN 8

class RGB 
{
public:
  RGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
    : rPin(redPin)
    , gPin(greenPin)
    , bPin(bluePin)
  {
    pinMode(rPin, OUTPUT);
    pinMode(gPin, OUTPUT);
    pinMode(bPin, OUTPUT);
  }

  setRGB(unsigned int red, unsigned int green, unsigned int blue) {
    analogWrite(rPin, red);
    analogWrite(gPin, green);
    analogWrite(bPin, blue);
  }
private:
  uint8_t rPin, gPin, bPin;
};

RGB led(R_PIN, G_PIN, B_PIN);

void setup() {
}

void loop() {
  led.setRGB(255, 0, 0);
  delay(500);
  led.setRGB(0, 255, 0);
  delay(500);
  led.setRGB(0, 0, 255);
  delay(500);
}
