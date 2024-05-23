#include <esp32-hal-log.h> // Include for logging (optional)

const int sensorPin = A0; // Analog input pin connected to the soil moisture sensor
const int ledPin = 13;    // Digital pin connected to the LED
const int threshold = 100; // Moisture level threshold (adjust based on your sensor)

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200); // Optional: Begin serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float moisture = map(sensorValue, 0, 1023, 100, 0); // Map sensor value to moisture percentage (0-100%)

  if (moisture < threshold) {
    digitalWrite(ledPin, HIGH); // Turn on LED if soil is dry
    log_d("Soil Moisture", "Soil is DRY (%d)", (int)moisture); // Optional logging
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED if soil is moist
    log_d("Soil Moisture", "Soil is MOIST (%d)", (int)moisture); // Optional logging
  }

  delay(1000); // Delay between readings
}
