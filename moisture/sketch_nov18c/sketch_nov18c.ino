int pumpPin = 7;  // Relay or pump control pin

void setup() {
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  if (sensorValue > 700) {
    digitalWrite(pumpPin, HIGH);  // Turn pump ON
  } else {
    digitalWrite(pumpPin, LOW);   // Turn pump OFF
  }
}

