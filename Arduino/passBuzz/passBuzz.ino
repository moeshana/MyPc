int buzzPin = 8;
int myNumber = 0;
int dl2 = 0;
int po = 0;
int controlPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(controlPin, INPUT);
}

void sound(int delayTime) {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
    delayMicroseconds(delayTime);
}

void loop() {
  po =  analogRead(controlPin);
  dl2 = 60 + (9940/ 1023) * po;
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(dl2);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(dl2);
}
