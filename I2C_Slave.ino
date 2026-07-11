#include <Wire.h>

const int LED = 10;  // LED on Uno pin 13

void setup() {
  pinMode(LED, OUTPUT);
  Wire.begin(8);  // UNO joins as slave, address = 8
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Nothing here, LED handled in receiveEvent
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    int command = Wire.read();
    if (command == 1) {
      digitalWrite(LED, HIGH); // LED ON
    } else {
      digitalWrite(LED, LOW);  // LED OFF
    }
  }
}
