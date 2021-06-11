int readPin = A3;
int ledPin = 8;
int v = 250;
int delayTime = 500;
double volt = 0.0;
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  v = analogRead(readPin); // 0 ~ 1023
  volt = (5./1023.) * v;
  if (volt <= 3) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(volt);
  delay(delayTime);
}
