#include <Servo.h>

// --- Pin Definitions ---
int relayPin = 7;   // Relay control pin
int servoPin = 9;   // Servo control pin

Servo myServo;      // Create a Servo object

void setup() {
  // Initialize the Relay pin as an output
  pinMode(relayPin, OUTPUT);

  // Initial State: Relay OFF and Servo attached
  digitalWrite(relayPin, LOW); // Relay OFF at start
  myServo.attach(servoPin);
  myServo.write(0);           // Initial servo position (0 degrees)
}

void loop() {
  // Cycle 1: Activate Relay and move Servo
  digitalWrite(relayPin, HIGH); // Turn Relay ON
  delay(10);                  // Wait for 1 second

  myServo.write(90);            // Move Servo to 90 degrees
  delay(1000);                  // Wait for 1 second

  // Cycle 2: Deactivate Relay and reset Servo
  digitalWrite(relayPin, LOW);  // Turn Relay OFF
  delay(1000);                  // Wait for 1 second

  myServo.write(0);             // Move Servo back to 0 degrees
  delay(1000);                  // Wait for 1 second
}
