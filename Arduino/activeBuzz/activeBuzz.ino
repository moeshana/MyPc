int buzzPin = 8;
int myNumber = 0;
double volt = 0;
int dl1 = 1;
int dl2 = 2;
int controlPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(controlPin, INPUT);
}

void loop() {
  tone(buzzPin, 2000, 200);
  delay(3000);

  

  // put your main code here, to run repeatedly:
//  Serial.println("Input your number: ");
//  while(Serial.available() == 0) {
//  }
//  myNumber = Serial.parseInt();
//  Serial.println(myNumber);
//  if (myNumber > 10) {
//    digitalWrite(buzzPin, HIGH);
//    delay(2000);
//    digitalWrite(buzzPin, LOW);
//  }   


//  myNumber = analogRead(controlPin);
//  volt = (5.0/1023.0) * myNumber;
//  Serial.println(volt);
//  while (volt >= 2.5) {
//    digitalWrite(buzzPin, HIGH);
//    volt = (5.0/1023.0) * analogRead(controlPin);
//  }
//  digitalWrite(buzzPin,LOW);

//  for (int i = 0; i <= 100; i++) {
//    digitalWrite(buzzPin, HIGH);
//    delay(dl1);
//    digitalWrite(buzzPin, LOW);
//    delay(dl1);
//  }
//
//   for (int i = 0; i <= 100; i++) {
//    digitalWrite(buzzPin, HIGH);
//    delay(dl2);
//    digitalWrite(buzzPin, LOW);
//    delay(dl2);
//  }

}
