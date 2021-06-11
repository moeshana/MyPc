#define latchPin 11
#define clockPin 9
#define dataPin 12
#define dt 500

//byte led = 0x01;
byte led = 0b10101010;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.println(led);
  
}

//shiftout() function
//MSBFIRST or LSBFIRST. 
//Most Significant Bit First, or, Least Significant Bit First.
//shiftout only works for 1 byte, if number larger than 255
//have to do two steps
//data = 500;
// shift out lowbyte
//shiftOut(dataPin, clock, LSBFIRST, data);
// shift out highbyte
//shiftOut(dataPin, clock, LSBFIRST, (data >> 8));
void loop() {
  // put your main code here, to run repeatedly:
//======================》example1
//  for (int i = 0; i < 7; i++) {
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, LSBFIRST, led);
//    digitalWrite(latchPin, HIGH);
//    led = led << 1;
//    delay(dt);
//  }
//  for (int i = 0; i < 7; i++) {
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, LSBFIRST, led);
//    digitalWrite(latchPin, HIGH);
//    led = led >> 1;
//    delay(dt);
//  }

//======================》example2
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, LSBFIRST, led);
//    digitalWrite(latchPin, HIGH);
//    delay(dt);
////    led = led / 128 + led * 2;  //shift left
//    led = led * 128 + led / 2;  //shift right

//=======================》example 3
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, led);
    digitalWrite(latchPin, HIGH);
    led = ~led;
    delay(dt*10);
}
