#include <DHT.h>
#include <DHT_U.h>

// -------------------- PIN DEFINITIONS --------------------
#define PIR_PIN 2             // PIR Motion Sensor
#define DHT_PIN 3             // DHT Sensor Data Pin
#define BUZZER_PIN 4          // Buzzer Pin
#define SMOKE_PIN A0          // MQ-2 Smoke Sensor Analog Pin

// Ultrasonic Sensor (HC-SR04)
#define TRIG_PIN 5
#define ECHO_PIN 6

#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// ----------------------------------------------------------
// ULTRASONIC MEASUREMENT FUNCTION
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 20000); // timeout 20ms
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

  int pirState = digitalRead(PIR_PIN);
  int smokeValue = analogRead(SMOKE_PIN);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float distance = getDistance();

  // Print values fast (NO big delays)
  Serial.print("PIR: "); Serial.print(pirState);
  Serial.print(" | Smoke: "); Serial.print(smokeValue);
  Serial.print(" | Temp: "); Serial.print(temperature);
  Serial.print(" | Humidity: "); Serial.print(humidity);
  Serial.print(" | Distance: "); Serial.println(distance);

  // Security triggers
  if (pirState == 1 || smokeValue > 500 || distance < 20 || temperature > 45) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(50);   // FAST RESPONSE (reduced delay)
}
