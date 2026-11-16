
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int moistureValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(sensorPin);
  
  lcd.setCursor(0, 0);
  lcd.print("Moisture:      ");
  lcd.setCursor(10,0);
  lcd.print(moistureValue);

  lcd.setCursor(0, 1);
  if (moistureValue < 400) {
    lcd.print("Status: Wet");
  } 
  else if (moistureValue < 700) {
    lcd.print("Status: Moist");
  } 
  else {
    lcd.print("Status: Dry");
  }

  delay(500);
}
