#define trigPin 5
#define echoPin 7

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  float distance = getDistanceSM();
  Serial.println(distance);
  delay(50);
}

float getDistanceSM() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  uint32_t duration = pulseIn(echoPin, HIGH);
  return duration / 58.2;
}
