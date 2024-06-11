Name: VENU KRISHNAN  
Company: CODTECH IT SOLUTIONS
ID: CT08DS1483
Domain: INTERNET OF THINGS
Duration: 1st June 2024 to 30th June 2024
Mentor: SRAVANI GOUNI

Overview of the Arduino-Based Weather Station Project
Objective
The goal of this project is to create a weather station using an Arduino that can measure and display temperature, humidity, and atmospheric pressure. This project is educational and practical, suitable for beginners and hobbyists interested in learning about electronics, sensors, and programming with Arduino.

Components Required
Arduino Board (e.g., Arduino Uno)
DHT22 or DHT11 Sensor
Measures temperature and humidity.
BMP180 or BMP280 Sensor
Measures atmospheric pressure.
Breadboard and Jumper Wires
For connecting components.
Resistors
If required for sensors.
LCD Display (Optional)
For displaying data in real-time.
Sensor Details
DHT22/DHT11 Sensor:
Provides digital readings for temperature and humidity.
DHT22 is more accurate and has a wider range than DHT11.
BMP180/BMP280 Sensor:
Measures atmospheric pressure.
BMP280 is an upgraded version of BMP180 with better performance and lower power consumption.
Wiring
DHT22/DHT11 Sensor:

VCC to 5V on Arduino.
GND to GND on Arduino.
Data pin to digital pin 2 on Arduino.
BMP180/BMP280 Sensor:

VCC to 3.3V or 5V on Arduino (depending on sensor specifications).
GND to GND on Arduino.
SCL to A5 (for I2C communication).
SDA to A4 (for I2C communication).
Software and Libraries
Arduino IDE:
Development environment for writing and uploading code to the Arduino.
Libraries:
DHT sensor library for DHT22/DHT11.
Adafruit Unified Sensor library for sensor abstraction.
Adafruit BMP085 Unified library for BMP180.
Adafruit BMP280 library for BMP280 (if used).
Code Explanation
Setup:
Initialize sensors.
Start serial communication for data output.
Loop:
Read temperature and humidity from DHT sensor.
Read atmospheric pressure from BMP sensor.
Calculate heat index.
Print all readings to the Serial Monitor.
