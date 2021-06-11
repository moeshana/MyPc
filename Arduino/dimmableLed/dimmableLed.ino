int ledPin = 5;
int downPin = A1;
int upPin = A0;
int buzzPin = 8;
int current = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(downPin, INPUT);
  pinMode(upPin, INPUT);
  Serial.begin(9600);
}

void upBehavior() {
  if (current < 255) {
    current++;
  }
}

void downBehavior() {
  if (current > 0) {
    current--;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  if (current >= 255) {
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }
  if (analogRead(upPin) == 1023) {
    upBehavior();
  }
  if (analogRead(downPin) == 1023) {
    downBehavior();
  }
  analogWrite(ledPin, current);
  Serial.println(current);
}
