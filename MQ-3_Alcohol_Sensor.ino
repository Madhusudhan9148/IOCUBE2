const int sensorPin = A0;  // Analog pin connected to the alcohol sensor output
const int buzzerPin = 35;  // Digital pin connected to the buzzer (replace with your actual pin)
const int threshold = 500;  // Adjust this value based on your sensor and desired alcohol level

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as output
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read analog value from the alcohol sensor

  // Map sensor value (0-1023) to a percentage for better interpretation (optional)
  // float alcoholPercent = (float)sensorValue / 1023.0 * 100.0;  // Uncomment if needed

  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH);  // Turn on buzzer if sensor value exceeds threshold
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off buzzer if sensor value is below threshold
  }

  delay(100);  // Delay between readings
}
