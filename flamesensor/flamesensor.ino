#define SENSOR_PIN 2
#define BUZZER_PIN 3

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Flame/Smoke sensor system initiated...");
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN);

  if (sensorValue == LOW) {  // LOW means flame/smoke detected for most sensors
    Serial.println("ALERT! Flame detected!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    Serial.println("No flame detected.");
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
