#define latchPin 11
#define clockPin 9
#define dataPin 12
#define soundPin 10
#define blue 2
#define green 3
#define red 4
#define black 5
#define yellow 6
#define dt 125

#define C 262
#define D 294
#define E 330
#define F 350
#define G 393
#define A 441
#define B 495
#define CC 525
#define DD 589
#define EE 661
#define AA 882

#define NO_SOUND -1



boolean bottomPress = false;
boolean gameStart = false;
int count = 0;
byte startLeds[14] = 
  {0xff, 0x00, 0xff, 0x00, 
   0x01, 0x02, 0x04, 0x08, 0x10,
   0x08, 0x04, 0x02, 0x01, 0xff};

int song[] = { G, G, G, E, F, G,
               G, B,
               A, A, A, A, F, A,
               G, 
               G, G, G, G, B, A,
               G, F,
               F, F, F, F, E, D,
               C,
               CC, CC, CC, CC, G, A,
               CC, CC, EE,
               DD, DD, DD, DD, CC, B,
               A, 
               B, B, B, B, B, CC,
               DD, G,
               B,B,CC,DD,CC,B,
               CC };

float duration[] = {1,1,1,1,1,1,
                    3,3,
                    1,1,1,1,1,1,
                    6,
                    1,1,1,1,1,1,
                    1, 5,
                    1,1,1,1,1.5,0.5,
                    6,
                    1,1,1,1,1,1,
                    2, 1, 3,
                    1,1,1,1.5,0.5,1,
                    6,
                    1,1,1,1,1,1,
                    3,3,
                    1,1,1,1,1,1,
                    6};

byte leds[5] = {0x01, 0x02, 0x04, 0x08, 0x10};
int len = 0;
int songPointer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
  pinMode(blue, INPUT); 
  pinMode(green, INPUT); 
  pinMode(red, INPUT); 
  pinMode(black, INPUT);
  pinMode(yellow, INPUT);  
  len = sizeof(song) / sizeof(int);

  delay(dt);
  
}

void loop() {
  //start...

  for (int i = 0; i < sizeof(startLeds); i++) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, startLeds[i]);
      digitalWrite(latchPin, HIGH);  
      count++;  

      if (songPointer > len) {
        songPointer = 0;
      }
      tone(soundPin, song[songPointer]);
      delay(150 * duration[songPointer]);
      noTone(soundPin);
      songPointer ++;
      
      if (pressBottom()) {
        bottomPress = true;
      }
      if (bottomPress && isBottomRelease()) {
        bottomPress = false;
        gameStart = true;
        break;
      }
      delay(dt);
  }
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
  digitalWrite(latchPin, HIGH);
  



  
  //game start...
  if (gameStart) {
    noTone(soundPin);
    songPointer = 0;
    delay(1000);
    setSeed(count);
    count = 1;
    boolean correct = true;
    while (correct) {
      byte *index;
      index = getArray(count);
      for (int i = 0; i < count; i++) {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, leds[index[i]]);
        digitalWrite(latchPin, HIGH);    
        delay(dt * 3);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
        digitalWrite(latchPin, HIGH);  
        delay(dt * 2);
      }
      int temp = -1;
      for (int y = 0; y < count; y++) {
        temp = waitingBottom();
        if (index[y] != temp) {
          correct = false; 
          gameStart = false;
          break;
        } else {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, LSBFIRST, leds[temp]);
          digitalWrite(latchPin, HIGH);  
          delay(dt * 2);
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
          digitalWrite(latchPin, HIGH);  
          delay(dt * 2);
        }
      }
      free(index);
      count++;
      delay(1000);
    }
    if (count >= 200) {
      gameStart = false;
      correct = false;
    }

    //end...
    for (int i = 0; i < sizeof(startLeds); i++) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, startLeds[i]);
      digitalWrite(latchPin, HIGH); 
      delay(25);
    } 
    delay(1000);
  }
}
