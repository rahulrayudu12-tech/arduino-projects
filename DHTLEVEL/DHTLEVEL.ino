#include "DHT.h"
#define DHTPIN 2       // DHT sensor connected to digital pin 2
#define DHTTYPE DHT11  // Change to DHT22 if using that

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();    // Humidity
  float t = dht.readTemperature(); // Temperature in °C

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  delay(2000);
}
