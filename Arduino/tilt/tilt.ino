int tiltPin = 3;
int tiltVal = 0;
int greenPin = 9;
int redPin = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  digitalWrite(tiltPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
  if (tiltVal == 0) {
     digitalWrite(redPin, LOW);
     digitalWrite(greenPin, HIGH);
  } else {
     digitalWrite(redPin, HIGH);
     digitalWrite(greenPin, LOW);
  }
}
