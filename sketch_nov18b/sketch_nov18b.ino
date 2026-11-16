import RPi.GPIO as GPIO
import time

# Pin Configuration
SENSOR_PIN = 17      # Moisture/Rainfall Sensor DO pin connected to GPIO17
BUZZER_PIN = 27      # Optional buzzer/LED connected to GPIO27

# GPIO Setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(SENSOR_PIN, GPIO.IN)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

print("Moisture/Rainfall Sensor System Initialized...")

try:
    while True:
        if GPIO.input(SENSOR_PIN) == 0:  # 0 indicates moisture/rain detected
            print("ALERT! Moisture/Rainfall Detected!")
            GPIO.output(BUZZER_PIN, GPIO.HIGH)  # Activate buzzer/LED
            time.sleep(0.5)
            GPIO.output(BUZZER_PIN, GPIO.LOW)
        else:
            print("No Moisture/Rainfall detected.")
            GPIO.output(BUZZER_PIN, GPIO.LOW)

        time.sleep(1)  # Check every second

except KeyboardInterrupt:
    print("Program stopped by user")
    GPIO.cleanup()
