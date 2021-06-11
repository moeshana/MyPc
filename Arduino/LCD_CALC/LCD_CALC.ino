#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
int n1;
int n2;
int res;
String op;
byte Heart[] = {   // 5 *8
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

String combineString(int n1, int n2, String op, int res) {
  String myRes = n1 + op  + n2 + "=" + res;
  return myRes;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, Heart);
  lcd.setCursor(0,0);
  lcd.setCursor(0, 1);
  lcd.write(0);
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input first #:");
  while (Serial.available() == 0);
  n1 = Serial.parseInt();
  lcd.clear();
  lcd.print("Your operator:");
  while (Serial.available() == 0);
  op = Serial.readString();
  lcd.clear();
  lcd.print("Input second #:");
  while (Serial.available() == 0);
  n2 = Serial.parseInt();
  boolean correct = false;
  if (op == "+") {
    res = n1 + n2;
    correct = true;
  } else {
    if (op == "-") {
      res = n1 - n2;
      correct = true;
    } else {
      if (op == "*") {
        res = n1 * n2;
        correct = true;
      } else {
        if (op == "/") {
          if (n2 == 0) {
            lcd.clear();
            lcd.print("lol[#/0]");
          } else {
            res = n1 / n2;
            correct = true;
          }
        } else {
          lcd.clear();
          lcd.print("Wrong operator!");
        }
      }
    }
  }
  if (correct) {
    lcd.clear();
    lcd.print("result :");
    lcd.setCursor(0,1);
    String stres = combineString(n1, n2, op, res);
    lcd.print(stres);
  }
  delay(5000);
}
