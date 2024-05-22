#define trigPin 7  // Digital pin connected to the ultrasonic sensor's trigger pin
#define echoPin 6  // Digital pin connected to the ultrasonic sensor's echo pin
#define ledPin 13  // Digital pin connected to the LED

const int threshold = 5; // Distance threshold in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);  // Set trigger pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance (assuming speed of sound is 343 m/s)
  float distance = duration * 0.034 / 2;

  // Check if distance is less than threshold
  if (distance < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on LED if distance is less than 5cm
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED otherwise
  }

  delay(100);  // Delay between readings
}
