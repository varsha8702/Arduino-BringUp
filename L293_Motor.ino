// Motor A (connected to OUT1, OUT2)
const int ENA = 9;   // Enable pin for Motor A
const int IN1 = 2;   // Control pin 1 for Motor A
const int IN2 = 3;   // Control pin 2 for Motor A

// Motor B (connected to OUT3, OUT4)
const int ENB = 10;  // Enable pin for Motor B
const int IN3 = 4;   // Control pin 1 for Motor B
const int IN4 = 5;   // Control pin 2 for Motor B

void setup() {
  // Motor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Motor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // === Forward both motors at full speed ===
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 255); // Full speed Motor A
  analogWrite(ENB, 255); // Full speed Motor B
  delay(2000);

  // === Stop both motors ===
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(1000);

  // === Backward both motors at half speed ===
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 128); // 50% speed Motor A
  analogWrite(ENB, 128); // 50% speed Motor B
  delay(2000);

  // === Stop both motors ===
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(1000);
}
