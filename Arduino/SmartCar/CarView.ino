int pingTravelTime; 


float get_distance() {
  float cm = 0;
  for (int i = 0; i <= 50; i++) {
    digitalWrite(TRIG_PIN, LOW); // make sure we get a clean HIGH pulse;
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, HIGH); //send signal;
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    pingTravelTime = pulseIn(ECHO_PIN, HIGH);
    cm += (pingTravelTime / 2.0) / 29.1;
  }
  cm /= 50; 
  return cm;
}


boolean Safe_Distance() {
  float cm = 0;
  for (int i = 0; i <= 50; i++) {
    digitalWrite(TRIG_PIN, LOW); // make sure we get a clean HIGH pulse;
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, HIGH); //send signal;
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    pingTravelTime = pulseIn(ECHO_PIN, HIGH);
    cm += (pingTravelTime / 2.0) / 29.1;
  }
  cm /= 50; 
  if (cm >= 15) {
    return true;
  } else {
    return false;
  }
}

void eye_move_event(int degree) {
  myServo.write(degree);
}

void turning_angle(int *left, int *right, int *state, int degree, int code) {
  int temp = (degree - 85) / 15; 
  int times = temp > 0? temp + 1:temp * (-1) + 1;
  if (degree >= 85) {
    for (int i = 0; i < times; i++) {
      running_car_at_speed(120, 0, RIGHT);
      delay(100);
    }
  } else {
    for (int i = 0; i < times; i++) {
      running_car_at_speed(0, 120, LEFT);
      delay(100);
    }
  }
}

void autoRuning(int *left, int *right, int *state){
  int degree = -10;
  float distance = -10;
  reset_stop(left, right, state);
  running_car();
  for (int i = 30; i<=160; i+=15) {
    eye_move_event(i);
    float temp = get_distance();
    if (temp >= distance) {
      degree = i;  
      distance = temp;
    }
  }
//  Serial.println(distance);
  if (distance >= 15) {
    *left = INIT_SPEED;
    *right = INIT_SPEED;
    *state = BACKWARD;
    running_car();
    delay(500);
    turning_angle(left, right, state, degree, 0);
    *left = INIT_SPEED;
    *right = INIT_SPEED;
    *state = FORWARD;
    eye_move_event(MID_POS);
  }
}

void reset_stop(int *left, int *right, int *state) {
  *left = 0;
  *right = 0;
  *state = STOP;
}
