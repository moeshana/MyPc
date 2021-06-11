int myNumber = 0;
String color;
int bluePin = 5;
int redPin = 6;
int greenPin = 4;
String msg = "Please type a color: ";
//String msg2 = "Your msg is: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available() == 0) {
    
  }
  color = Serial.readString();
  Serial.println(color);
  if (color.equals("red")) {
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
  } 
  if (color.equals("blue")) {
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
  }
  if (color.equals("green")) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
  }
  if (color.equals("all")) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, HIGH);
  }    
  
  
//  myNumber = Serial.parseInt();
//  Serial.print(msg2);
//  Serial.println(myNumber);
}
