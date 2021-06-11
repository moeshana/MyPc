//int speedPin=5;
//int dir1=4;
//int dir2=3;
//int mSpeed=90;
#include <DHT.h>
#define TYPE DHT11
int temp = A5;
DHT HT(temp, TYPE);
float humidity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  HT.begin();
  Serial.begin(9600);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.println(tempF);

}
