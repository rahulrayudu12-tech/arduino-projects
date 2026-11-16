// --------------------------------------------------
// BANK LOCKER SECURITY SYSTEM
// Motion + Smoke + Temperature + Humidity + Buzzer
// --------------------------------------------------

#include <DHT.h>

#define PIR_PIN 2          // PIR Motion Sensor (Digital)
#define DHT_PIN 3          // DHT11/DHT22 Sensor (Digital)
#define BUZZER_PIN 4       // Buzzer/Speaker
#define SMOKE_PIN A0       // MQ-2/MQ-135 Smoke Sensor (Analog)

#define DHT_TYPE DHT11     // Change to DHT22 if using DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SMOKE_PIN, INPUT);

  dht.begin();

  Serial.println("Bank Locker Security System Started...");
  delay(1000);
}

void loop() {

  // -----------------------------
  // Read Motion Sensor
  // -----------------------------
  int motion = digitalRead(PIR_PIN);

  // -----------------------------
  // Read Smoke Sensor
  // -----------------------------
  int smokeLevel = analogRead(SMOKE_PIN);

  // -----------------------------
  // Read Temperature & Humidity
  // -----------------------------
  float temperature = dht.readTemperature();   // Celsius
  float humidity = dht.readHumidity();

  // Check DHT read errors
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error reading DHT sensor!");
    return;
  }

  // Print on Serial Monitor
  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Smoke: ");
  Serial.print(smokeLevel);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print("C | Humidity: ");
  Serial.println(humidity);

  // -----------------------------
  // ALERT CONDITIONS
  // -----------------------------
  bool alert = false;

  // Motion detection
  if (motion == HIGH) {
    Serial.println("⚠️ ALERT: Motion detected!");
    alert = true;
  }

  // Smoke detection threshold
  if (smokeLevel > 350) {   // Adjust as per your sensor
    Serial.println("🔥 ALERT: Smoke/Gas detected!");
    alert = true;
  }

  // High temperature alert
  if (temperature > 45) {
    Serial.println("🔥 ALERT: High temperature detected!");
    alert = true;
  }

  // -----------------------------
  // BUZZER / SPEAKER ALERT
  // -----------------------------
  if (alert) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(300);
}
