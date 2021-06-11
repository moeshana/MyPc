float getNum(float old, float cur) {
  if (cur < 48 || cur > 58) {
    return old;
  }
  return old * 10 + (cur - 48);
}


void calc(char myChar, float first, float second, LiquidCrystal_I2C lcd) {
  float res = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(first);
  if (myChar == 'A') {
    lcd.print("+");
    res = first + second;
  } else {
    if (myChar == 'B') {
      lcd.print("-");
      res = first - second;
    } else {
      if (myChar == 'C') {
        lcd.print("*");
        res = first * second;
      } else {
        if (myChar == 'D') {
          if (second == 0) {
            lcd.clear();
            lcd.print("Error by div 0");
            return;
          } else {
            lcd.print("/");
            res = first / second;
          }
        } else {
          lcd.clear();
          lcd.print("WRONG OPERATOR");
          return;
        }
      }
    }
  }
  lcd.print(second);
  lcd.print("=");
  lcd.setCursor(0,1);
  lcd.print(res); 
}
