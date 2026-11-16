int sensorPin = A0;     // Moisture sensor analog output connected to A0
int sensorValue = 0;    // Variable to store value from sensor

void setup() {
  Serial.begin(9600);   // Start serial communication
}

void loop() {
  sensorValue = analogRead(sensorPin);   // Read analog value (0 - 1023)

  Serial.print("Moisture Value: ");
  Serial.println(sensorValue);

  // Interpreting moisture level
  if (sensorValue >= 0 && sensorValue < 300) {
    Serial.println("Status: 🌧 Very Wet");
  }
  else if (sensorValue >= 300 && sensorValue < 700) {
    Serial.println("Status: 🌿 Moist");
  }
  else if (sensorValue >= 700 && sensorValue <= 1023) {
    Serial.println("Status: 🔥 Dry");
  }

  Serial.println("--------------------------");
  delay(500);  // Pause for half a second
}
