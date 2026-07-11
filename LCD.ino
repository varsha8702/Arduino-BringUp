#include <LiquidCrystal.h>

// Initialize the LCD with interface pins: RS, EN, D4, D5, D6, D7
// Update pin numbers as per your actual wiring
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Set up LCD columns and rows
  lcd.begin(16, 2);

  // Set cursor to column 3, row 1 (0-indexed → row=0, col=2)
  lcd.setCursor(2, 0);
  lcd.print("Hello, World!");

  // Set cursor to column 3, row 2 (0-indexed → row=1, col=2)
  lcd.setCursor(2, 1);
  lcd.print("EMBTRON INDIA!");
}

void loop() {
  // Do nothing (infinite loop like while(1) in C)
}