
// Define the pin where the LED is connected
const int ledPin = 2;  // Change this pin if needed

void setup() {
  // Initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED ON
  digitalWrite(ledPin, HIGH);
  delay(5000);  // Wait for 5 seconds

  // Turn the LED OFF
  digitalWrite(ledPin, LOW);
  delay(1000);  // Wait for 1 second
}