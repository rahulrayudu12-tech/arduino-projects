# Arduino and IoT Projects

A collection of Arduino sketches and IoT experiments covering sensor integration, home/bank security systems, environmental monitoring, and motor/actuator control.

## Project Directory & Code Explanations

### 1. Bank Vault & Locker Security
- **`2/2.ino`**: Multi-sensor bank locker alert system. Integrates a PIR motion detector (Pin 2), an MQ-2 smoke/gas sensor (A0), a DHT11 temperature/humidity sensor (Pin 3), and an HC-SR04 ultrasonic distance sensor (Pins 5 & 6). If motion is seen, smoke exceeds 500, temperature rises above 45°C, or an object approaches within 20 cm, a buzzer on Pin 4 sounds.
- **`bank/bank.ino`**: Security logger for vault monitoring. Reads PIR motion, MQ-2 analog smoke levels, and DHT11 ambient conditions. Outputs human-readable alerts and sensor metrics to the Serial Monitor at 9600 baud.
- **`banksafety/banksafety.ino`**: Low-latency security monitor combining ultrasonic ranging with motion and smoke detection to quickly flag nearby intruders or hazards.
- **`flamesensor/flamesensor.ino`**: Dedicated flame alarm. An infrared flame detector on Pin 2 triggers an active buzzer on Pin 3 when fire radiation is detected.
- **`smokesensor/smokesensor.ino`**: MQ-2 gas and smoke monitor on pin A5 with dual-LED visual status. A green LED (Pin 11) indicates safe conditions; crossing the analog threshold (350) turns on a red LED (Pin 12) and plays an alert tone on a buzzer (Pin 10).

### 2. Soil Moisture & Smart Irrigation
- **`moisture/moisture.ino`**: Soil hydration monitor using an analog probe on A0 and a 16x2 LCD with an I2C backpack (`0x27`). Displays the numerical reading and categorizes soil state as Wet, Moist, or Dry.
- **`moisture/sketch_nov18c/sketch_nov18c.ino`**: Automated watering setup. Reads soil moisture on A0 and triggers a 5V relay module on Pin 7 to activate a water pump when moisture is low.
- **`moisturelcd/moisturelcd.ino`**: Dedicated I2C LCD moisture status display refreshing every 500ms.
- **`withoutlcd/withoutlcd.ino`**: Lightweight soil moisture logger that prints raw analog values and status tags (Very Wet, Moist, Dry) directly to the Serial Monitor without an external display.
- **`sketch_nov18b/sketch_nov18b.ino`**: A Python script designed for Raspberry Pi GPIO. Reads a moisture/rain sensor digital output on BCM GPIO 17 and pulses a buzzer on GPIO 27 when precipitation is detected.

### 3. Temperature & Humidity Telemetry
- **`DHT.h/DHT.h.ino`**: Reads ambient humidity and temperature in both Celsius and Fahrenheit from a DHT sensor on Pin 2, and calculates the heat index.
- **`DHTLEVEL/DHTLEVEL.ino`**: Baseline test sketch for initializing a DHT11 on Pin 2 and reading temperature.
- **`DHTLEVSENSOR/DHTLEVSENSOR.ino`**: Diagnostic sketch for sampling and printing dual-scale temperature and relative humidity with sensor error validation.

### 4. Wireless & Motor Control
- **`bluetooth/bluetooth.ino`**: Serial Bluetooth control (HC-05 / HC-06). Listens for character commands over UART: sending `'1'` turns digital Pin 13 ON, and sending `'0'` turns it OFF.
- **`relayservo/relayservo.ino`**: Combined actuator demonstration. Alternates between activating a 5V relay on Pin 7 with an SG90 servo turned to 90°, and deactivating the relay with the servo reset to 0°.

## Included Libraries (`libraries/`)
Contains common local library folders for LCD I2C communication and sensor support needed by the sketches.

## How to Use
1. Open the desired `.ino` sketch in the Arduino IDE.
2. Select your development board (e.g., Arduino Uno) and the active COM port.
3. Install or reference the required sensor libraries.
4. Compile and upload to the board.
5. Open the Serial Monitor at 9600 baud to view debug messages.
