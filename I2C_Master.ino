#include <Wire.h>

const int BUTTON = 10;  // Button on Mega pin 10

void setup() {
  pinMode(BUTTON, INPUT_PULLUP); // Button uses pull-up
  Wire.begin();  // Mega as I2C master
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  Wire.beginTransmission(8); // Send to UNO at address 8
  if (buttonState == LOW) {  // Button pressed
    Wire.write(1);           // Command: LED ON
  } else {
    Wire.write(0);           // Command: LED OFF
  }
  Wire.endTransmission();

  delay(200);
}
