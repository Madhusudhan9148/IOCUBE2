/*
  Read Temperature, Humidity, and Control LED
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date: November 2023

  Tested using ESP32-WROOM32
*/

#include <Bonezegei_DHT11.h>

const int ledPin = 13;  // Digital pin connected to the LED
const float temperatureThreshold = 30.0; // Threshold temperature in Celsius

// DHT11 signal pin
Bonezegei_DHT11 dht(12);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  dht.begin();
}

void loop() {
  if (dht.getData()) {
    float tempDeg = dht.getTemperature();
    float tempFar = dht.getTemperature(true);
    int hum = dht.getHumidity();

    Serial.printf("Temperature: %0.1lf°C %0.1lf°F Humidity:%d \n", tempDeg, tempFar, hum);

    // Check if temperature exceeds threshold
    if (tempDeg > temperatureThreshold) {
      digitalWrite(ledPin, HIGH);  // Turn on LED if temperature is above threshold
      Serial.println("Temperature exceeded threshold. LED turned ON.");
    } else {
      digitalWrite(ledPin, LOW);   // Turn off LED if temperature is below threshold
      Serial.println("Temperature within threshold. LED turned OFF.");
    }
  }

  delay(2000);  // Delay at least 2 seconds for DHT11 to read data
}
