#include <DHT.h>
#include <DHT_U.h>

// -------------------- PIN DEFINITIONS --------------------
#define PIR_PIN     2    // PIR Motion Sensor
#define DHT_PIN     3    // DHT Sensor Data Pin
#define BUZZER_PIN  4    // Buzzer Pin
#define SMOKE_PIN   A0   // MQ-2 Smoke/Flame Sensor Analog Pin
#define TRIG_PIN    5    // Ultrasonic Trigger Pin
#define ECHO_PIN    6    // Ultrasonic Echo Pin

#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// ----------------------------------------------------------
// Function to read distance from HC-SR04
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 20000); // 20ms timeout
  float distance = duration * 0.034 / 2;
  return distance;
}

// ----------------------------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SMOKE_PIN, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();

  Serial.println("🔐 Bank Locker Security System Started...");
}

// ----------------------------------------------------------
void loop() {
  // --- READ SENSORS ---
  int pirState = digitalRead(PIR_PIN);
  int smokeValue = analogRead(SMOKE_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float distance = getDistance();

  // --- CHECK DHT SENSOR ERROR ---
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ DHT Sensor Error!");
    delay(50);
    return;
  }

  // --- PRINT SENSOR VALUES ---
  Serial.print("PIR: "); Serial.print(pirState);
  Serial.print(" | Smoke: "); Serial.print(smokeValue);
  Serial.print(" | Temp: "); Serial.print(temperature);
  Serial.print(" | Humidity: "); Serial.print(humidity);
  Serial.print(" | Distance: "); Serial.println(distance);

  // --- BUZZER: ANY SENSOR TRIGGER ---
  if (pirState == HIGH || smokeValue > 500 || temperature > 45 || distance < 20) {
    // Short beep 100ms
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(50); // Fast loop
}
