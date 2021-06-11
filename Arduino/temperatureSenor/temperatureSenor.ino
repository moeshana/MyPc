#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define TYPE DHT11
#define SENSE_PIN 2
#define powerPin 7

#define DT 500
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
DHT HT(SENSE_PIN, TYPE);
float humidity;
float tempC;
float tempF;

byte degree[] = {
  B00100,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,  
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  HT.begin();
  lcd.createChar(0, degree);
  pinMode(powerPin, HIGH);
  delay(DT);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(humidity);
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.write(0);
  lcd.print("C");
  lcd.print(" : ");
  lcd.print(tempF);
  lcd.print("F");
  delay(DT);
}
