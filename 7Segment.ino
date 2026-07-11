// Segment pins (a, b, c, d, e, f, g)
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Digit enable pins for the two displays
int digit1 = 9;  // Tens place
int digit2 = 10; // Ones place

// Digit-to-segment mapping (common cathode)
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  // Set digit control pins as outputs
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
}

void displayDigit(int digit, int position) {
  // Set the segments for the digit
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[digit][i]);
  }
  // Enable the correct display
  if (position == 1) { // Tens
    digitalWrite(digit1, LOW);   // Active LOW
    delay(5);
    digitalWrite(digit1, HIGH);
  } else { // Ones
    digitalWrite(digit2, LOW);
    delay(5);
    digitalWrite(digit2, HIGH);
  }
}

void loop() {
  for (int num = 0; num < 100; num++) {
    unsigned long startTime = millis();
    // Show the same number for 1 second using multiplexing
    while (millis() - startTime < 1000) {
      int tens = num / 10;
      int ones = num % 10;
      displayDigit(tens, 1);
      displayDigit(ones, 2);
    }
  }
}
