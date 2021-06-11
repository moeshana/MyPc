#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

#define DT 500
#define ROWS 4
#define COLS 4

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  delay(DT);
}


void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Input 1stNum #: ");
  lcd.setCursor(0,1);
  double first = 0;
  double second = 0;
  boolean isDec = false;
  int count = 0;
  double decimal = 0;
  char myChar;
  while ((myChar = myKeypad.getKey()) != '#') {
    if (myChar) {
      if (myChar == '*') {
        isDec = true;
        lcd.print(".");
        continue;
      } else {
        lcd.print(myChar);
      }
      if (isDec) {
        decimal = getNum(decimal, myChar);
        count++;
      } else {
        first = getNum(first, myChar);
      }
    }
  }
  
  if(isDec) {
    isDec = false;
    for (int i = count; i > 0; i--) {
      decimal = decimal / 10;
    }
    first = first + decimal;
    count = 0;
    decimal = 0;
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Input 2ndNum #: ");
  lcd.setCursor(0,1);
  while ((myChar = myKeypad.getKey()) != '#') {
    if (myChar) {
      if (myChar == '*') {
        isDec = true;
        lcd.print(".");
        continue;
      } else {
        lcd.print(myChar);
      }
      if (isDec) {
        decimal = getNum(decimal, myChar);
        count++;
      } else {
        second = getNum(second, myChar);
      }
    }
  }
  if(isDec) {
    isDec = false;
    for (int i = count; i > 0; i--) {
      decimal = decimal / 10;
    }
    second = second + decimal;
    count = 0;
    decimal = 0;
  }

  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Input operator: ");
  lcd.setCursor(0,1);
  lcd.print("A:+,B:-,C:*,D:/");
  while(!(myChar = myKeypad.getKey())) {}
  if (myChar) {
    calc(myChar, first, second, lcd);    
  }
  
  delay(10 * DT);
}
