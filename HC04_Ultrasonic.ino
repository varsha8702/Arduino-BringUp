#include <LiquidCrystal.h>

// LCD: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 4, 5, 6, 3);

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Initialize LCD and Ultrasonic sensor pins
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Get distance in cm
  unsigned int distance = readUltrasonicDistance();

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm   "); // Extra space to clear previous chars

  delay(500); // Wait 500ms
}

unsigned int readUltrasonicDistance() {
  // Send 10us pulse to trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH);

  // Convert to distance in cm
  unsigned int distanceCm = duration * 0.034 / 2;

  return distanceCm;
}
