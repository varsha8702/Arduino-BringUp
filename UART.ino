char received_data;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    received_data = (char)Serial.read();

    // Ignore carriage return and newline
    if (received_data == '\r' || received_data == '\n') {
      return; // skip processing
    }

    Serial.print("received data is: ");

    if (received_data == '1') {
      digitalWrite(13, HIGH);
      Serial.println(received_data);
    }
    else if (received_data == '0') {
      digitalWrite(13, LOW);
      Serial.println(received_data);
    }
    else {
      Serial.println(" invalid");
    }
  }
}

