const int irPin = 2;       // IR sensor output connected to digital pin 2
const int ledPin = 13;     // LED connected to pin 13 (built-in)

void setup() {
  pinMode(irPin, INPUT);   // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  int irValue = digitalRead(irPin); // Read IR sensor state

  if (irValue == LOW) {
    // Object detected
    digitalWrite(ledPin, LOW);
  } else {
    // No object
    digitalWrite(ledPin, HIGH);
  }
}
