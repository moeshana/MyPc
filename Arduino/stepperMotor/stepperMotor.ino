#include <Stepper.h>
int stepPerRevolution = 2048;
int motSpeed = 10; // can't run very fast;
int sw = A0;
int clockwise = 1;
int swState = 0;
Stepper myStepper(stepPerRevolution, 8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sw, INPUT);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int newState = (digitalRead(sw));
  if (swState == 0 && newState == 1) {
     clockwise *= -1;
  }
  swState = newState;
  if (clockwise == 1) {
    myStepper.step(1);
  } else {
    myStepper.step(-1);
  }
  delay(10);
}
