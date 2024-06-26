#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_BMP085.h> // For BMP180
// #include <Adafruit_BMP280.h> // Uncomment this line if using BMP280

#define DHTPIN 2      // Pin which is connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp; // For BMP180
// Adafruit_BMP280 bmp; // Uncomment this line if using BMP280

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1) {}
  }
  // If using BMP280, use this initialization instead
  // if (!bmp.begin()) {
  //   Serial.println("Could not find a valid BMP280 sensor, check wiring!");
  //   while (1) {}
  // }
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read pressure from BMP sensor
  float pressure = bmp.readPressure() / 100.0F; // hPa

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.print(" *F\t");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  // Wait a few seconds between measurements
  delay(2000);
}