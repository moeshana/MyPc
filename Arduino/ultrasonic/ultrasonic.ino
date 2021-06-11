#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define DT 500
#define TRIG_PIN 12
#define ECHO_PIN 11

int pingTravelTime; 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  delay(DT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance : ");
  digitalWrite(TRIG_PIN, LOW); // make sure we get a clean HIGH pulse;
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH); //send signal;
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  pingTravelTime = pulseIn(ECHO_PIN, HIGH); //read echo pin;
  float cm = (pingTravelTime / 2.0) / 29.1;
  Serial.print(cm);
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print("cm");
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(2);
  Serial.print(",");
  Serial.println(5);
  delay(DT);
  
}
