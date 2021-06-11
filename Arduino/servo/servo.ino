#include <Servo.h>
int redPin = 6;
int greenPin = 5;
int servoPin = 9;
int servoPos = 90;
int controlX = A1;
int controlY = A2;
int spin = 11;
int xVal;
int yVal;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(controlX, INPUT);
  pinMode(controlY, INPUT);
  pinMode(spin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(servoPos);
  analogWrite(greenPin, 127);
}

void loop() {
//    digitalWrite(redPin, HIGH);
//    digitalWrite(greenPin, HIGH);
    yVal = analogRead(controlY);
    int temp = 255.0 / 1023.0 * yVal;
    analogWrite(greenPin, temp);
    xVal = analogRead(controlX);
    int angle = 165 - (165.0 / 1023.0 * xVal) + 7;
    myServo.write(angle);
    delay(200);

//  type a angle from serial to rotate servo 
//  Serial.print("Input Angle for the Servo: ");
//  while(Serial.available() == 0) {
//  }
//  int temp = Serial.parseInt();
//  if (temp >= 165) {
//    temp = 165; 
//  } else {
//    if (temp <= 0) {
//      temp = 0;
//    }
//  }
//  servoPos = temp;
//  Serial.println(temp);
//  myServo.write(servoPos);

//    use photo resisitor to control servo
//    int darkness = analogRead(controlPin);
//    servoPos = 165.0 / 255.0 * darkness; 
//    myServo.write(servoPos);
//    delay(100);
}
