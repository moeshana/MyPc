#include <IRremote.h>
#include <Servo.h>
#include "cons.h"

int servoPos = MID_POS;
int leftSpeed = 0;
int rightSpeed = 0;
int carState = STOP;
IRrecv IR(IR_PIN);
decode_results cmd;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(DIR_1, OUTPUT);
  pinMode(DIR_2, OUTPUT);
  pinMode(ENABLE_A, OUTPUT);
  pinMode(ENABLE_B, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  digitalWrite(LED_PIN, LOW);
  IR.enableIRIn();
  myServo.attach(SERRO_PIN);
  myServo.write(servoPos);
  delay(delayTime);
}

void loop() {
  if (IR.decode(&cmd)) {
    IR.resume();
    unsigned long val = cmd.value;
    if (val != 0xffffffff && val != 0xff) {
      getCommand(val);
    }
  }
  
  if (!Safe_Distance()) {
    if (carState != 5) {
      digitalWrite(LED_PIN, HIGH);
      autoRuning(&leftSpeed, &rightSpeed, &carState);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    running_car();
  }
  delay(delayTime);
}

void running_car_at_speed(int left, int right, int carState) {
//  Serial.print(left);
//  Serial.print(" : ");
//  Serial.print(right);
//  Serial.print(" : ");
//  Serial.println(carState);
  if (carState == 8) {
    digitalWrite(DIR_1, HIGH);
    digitalWrite(DIR_2, LOW);
  } else {
    digitalWrite(DIR_2, HIGH);
    digitalWrite(DIR_1, LOW);
  }
  analogWrite(ENABLE_A, left);
  analogWrite(ENABLE_B, right);
}

void running_car() {
  running_car_at_speed(leftSpeed, rightSpeed, carState);
}
