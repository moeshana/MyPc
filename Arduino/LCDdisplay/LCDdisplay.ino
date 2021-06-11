#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(3, 0); // Set the cursor on the first column and first row.
  lcd.print("Hello World!"); // Print the string "Hello World!"
  lcd.setCursor(1, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("Shana");
  delay(2500);
  lcd.clear();
  delay(1000);
}
