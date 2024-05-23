const int pirPin = 2; // Digital pin connected to the PIR sensor output
const int ledPin = 13; // Digital pin connected to the LED

void setup() {
  pinMode(pirPin, INPUT); // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  int pirValue = digitalRead(pirPin); // Read digital value from PIR sensor

  if (pirValue == HIGH) { // Check for motion detection (HIGH indicates movement)
    digitalWrite(ledPin, HIGH); // Turn on LED if motion is detected
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED if no motion is detected
  }
}
