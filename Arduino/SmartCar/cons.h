#ifndef _CONS_H
//used already pin : 5,6,8,9,10
// 3 11 12

//speed control
#define STEP_SPEED 10
#define INIT_SPEED 80
#define MAX_SPEED 255
#define MIN_SPEED 0

#define TURN_SPEED 100

//car state
#define FORWARD 2
#define BACKWARD 8
#define LEFT 4
#define RIGHT 6
#define STOP 5

//IR remote control
#define IR_PIN 10

//Servo control
#define SERRO_PIN 3
#define MID_POS 85
#define LOW_POS 20
#define HIGH_POS 150


//ultrasonic
#define TRIG_PIN 12
#define ECHO_PIN 11
#define LED_PIN 2

//DC motor control
#define ENABLE_A 5
#define ENABLE_B 6
#define DIR_1 8
#define DIR_2 9
#define delayTime 225

#endif
