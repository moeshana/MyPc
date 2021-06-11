#define DELAY_TIME 50
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(DELAY_TIME);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (float i = 0; i < 2 * 3.1415926537; i += 0.01) {
    Serial.print(1);
    Serial.print(",");
    Serial.print("-1");
    Serial.print(",");
    Serial.print(sin(i));
    Serial.print(",");
    Serial.println(cos(i));
    delay(DELAY_TIME);
  }

  
}
