#define resistor 0
#define buzzer 9

int frequency = 0;

void setup() {
 pinMode(resistor, INPUT);
 pinMode(buzzer, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  frequency = analogRead(resistor);
  frequency = map(frequency, 0, 1023, 31, 2000);
  tone(buzzer, frequency);
  Serial.println(String(frequency) + " Hz");
}
