#include <stdio.h>

void getCommand(unsigned long val) {
//  Serial.println(val);
  if (val == 3772817503) {
    Serial.println("forward");
    move_event(&leftSpeed, &rightSpeed, &carState, 2);
  }
  if (val == 3772821583) {
    Serial.println("backward");
    move_event(&leftSpeed, &rightSpeed, &carState, 8);
  }
  if (val == 3772780783) {
    Serial.println("left");
    turning(&leftSpeed, &rightSpeed, &carState, 4);
  }
  if (val == 3772797103) {
    Serial.println("right");
    turning(&leftSpeed, &rightSpeed, &carState, 6);
  }
  if (val == 3772813423) {
    Serial.println("break");
    move_event(&leftSpeed, &rightSpeed, &carState, 5);
  }


  if (val == 3772784863) {
    Serial.println("forward_left");
    turning_angle(&leftSpeed, &rightSpeed, &carState, 0, 0);
  }

  
//  if (val == 3772801183) {
//    Serial.println("forward_right");
//  }
//    if (val == 3772788943) {
//    Serial.println("backward_left");
//  }
//  if (val == 3772805263) {
//    Serial.println("backward_right");
//  }
}
