const int ldrPin = A0;  // Analog pin connected to the LDR sensor
const int ledPin = 13;  // Digital pin connected to the LED (replace with your actual pin)
const int threshold = 500;  // Adjust this value based on your LDR and desired light level

void setup() {
  Serial.begin(9600);  // Initialize serial communication for output
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
}

void loop() {
  int sensorValue = analogRead(ldrPin);  // Read analog value from the LDR sensor

  Serial.print("LDR Value: ");
  Serial.println(sensorValue);  // Print the sensor reading to the serial monitor

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED if LDR value is above threshold
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED if LDR value is below threshold
  }

  delay(100);  // Delay between readings
}
