#include "cons.h"

void turning(int *left, int *right, int *carState, int code) {
  if (code == LEFT) {
    *right = 0;
    *left = TURN_SPEED;
    *carState = LEFT;
  }
  if (code == RIGHT) {
    *left = 0;
    *right = TURN_SPEED;
    *carState = RIGHT;
  }
  return;
}


void move_event(int *left, int *right, int *carState, int code) {
  if (code == STOP) {
    *left = MIN_SPEED;
    *right = MIN_SPEED;
    *carState = STOP;
    return;
  }
  if (code == FORWARD) { 
    if ((*carState == FORWARD) | (*carState == STOP)) {
      *left = (*left) + STEP_SPEED;
      *right = (*right) + STEP_SPEED;
      *carState = FORWARD;
    } else {
      if (*carState == BACKWARD) {
        *left = (*left) - STEP_SPEED;
        *right = (*right) - STEP_SPEED;
      } else {
        *left = INIT_SPEED;
        *right = INIT_SPEED;
        *carState = FORWARD;
      }
    }
  }
  if (code == BACKWARD) {
    if (*carState == STOP) {
       *left = INIT_SPEED;
       *right = INIT_SPEED;
       *carState = BACKWARD;
    } else {
      if (*carState == BACKWARD) {
        *left = (*left) + STEP_SPEED;
        *right = (*right) + STEP_SPEED;
      } else {
        if (*carState == FORWARD) {
          *left = (*left) - STEP_SPEED;
          *right = (*right) - STEP_SPEED;
        } else {
          *left = INIT_SPEED;
          *right = INIT_SPEED;
          *carState = BACKWARD;
        }
      }
    }
  }
  if ((*left == MIN_SPEED) && (*right == MIN_SPEED)) {
    *carState = STOP;
  } 
  if (*left <= INIT_SPEED) {
    *left = INIT_SPEED;
  }
  if (*right <= INIT_SPEED) {
    *right = INIT_SPEED;
  }
  if (*left >= MAX_SPEED) {
    *left = MAX_SPEED;
  }
  if (*right >= MAX_SPEED) {
    *right = MAX_SPEED;
  }
  return;
}
