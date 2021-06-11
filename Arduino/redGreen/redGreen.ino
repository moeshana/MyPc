int redPin = 8;
int greenPin = 7;
int buzzPin = 6;
int controlPin = A1;
int photoResisior = 0;
boolean first = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(controlPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  photoResisior = analogRead(controlPin);
  Serial.println(photoResisior);
  if (photoResisior >= 100) {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(buzzPin,HIGH);
    delay(15);
    digitalWrite(buzzPin, LOW);
    delay(1000);
    first = true;
  } else {
    if (first) {
      digitalWrite(greenPin,HIGH);
      digitalWrite(redPin,HIGH);
      delay(2000);
      first = false;
    }
    digitalWrite(redPin,LOW);
    digitalWrite(buzzPin,HIGH);
    delay(15);
    digitalWrite(buzzPin, LOW);
    delay(400);
  }  
}
