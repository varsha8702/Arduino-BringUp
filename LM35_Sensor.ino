#include <LiquidCrystal.h>
// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int lm35Pin = A0; // LM35 analog output connected to A0

void setup() {
  lcd.begin(16, 2);           // Initialize LCD
  analogReference(DEFAULT);   // Use 5V reference
}

void loop() {
  int adcValue = analogRead(lm35Pin);      // Read analog value (0–1023)
  float voltage = adcValue * (5.0 / 1023);  // Convert to voltage
  float tempC = voltage * 100.0;           // Convert to Celsius (10mV per °C)

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 2); // Show 2 decimal places
  lcd.print((char)223); // Degree symbol
  lcd.print("C   "); // Space to clear residue

  delay(1000); // Wait 1 second
}