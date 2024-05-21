void setup() {
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(35, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(35, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(35, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
