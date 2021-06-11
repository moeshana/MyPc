int dir1 = 8;
int dir2 = 9;
int mspPin = 11;
int motorspeed = 255;
int buzz = 3;

int yControl = A0;
int xControl = A1;

int oldValue = 0;
int sw = 12;
int tilt = 10;
boolean start = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(mspPin, OUTPUT);
  pinMode(sw, INPUT);
  pinMode(tilt, INPUT);
  pinMode(xControl, INPUT);
  pinMode(yControl, INPUT);
  digitalWrite(tilt, HIGH);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(xControl));
  Serial.print(" - ");
  Serial.println(analogRead(yControl));
  int newValue = digitalRead(sw);
  if (newValue == 1 && oldValue == 0) {
    start = !start;
  } 
  oldValue = newValue;
  int tiltState = digitalRead(tilt);
  
  motorspeed = 175.0 / 1023.0 * analogRead(xControl) + 80;
  if (analogRead(yControl) > 500) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  } else {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  if (start) {
    analogWrite(mspPin, motorspeed);
  } else {
    analogWrite(mspPin, 0);
  }

  if (start && tiltState == 1) {
    analogWrite(mspPin, 0);
  } else {
    if (start && tiltState == 0) {
        analogWrite(mspPin, motorspeed);
    }
  }
  
  Serial.print(start);
  Serial.print(" : ");
  Serial.print(tiltState);
  Serial.println();
}
