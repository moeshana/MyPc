#include <stdio.h>
#include <stdlib.h>

boolean pressBottom() {
  return checkBottomPress() >= 0 ? true : false;
}

boolean isBottomRelease() {
  if (digitalRead(blue) + digitalRead(green) + 
      digitalRead(red) + digitalRead(black) + 
      digitalRead(yellow) == 0) {
        return true;  
  } else {
    return false;
  }
}

int checkBottomPress() {
  if (digitalRead(blue) == 1) {
    return 0;
  }
  if (digitalRead(green) == 1) {
    return 1;
  }
  if (digitalRead(red) == 1) {
    return 2;
  }
  if (digitalRead(black) == 1) {
    return 3;
  }
  if (digitalRead(yellow) == 1) {
    return 4;
  }
  return -1;
}

int waitingBottom() {
  while(true) {
    int i = checkBottomPress();
    Serial.println(i); 
    if (i >= 0) {
      if (isBottomRelease()) {
        return i;
      }
    }
  }
}

void setSeed(int count) {
  srand(count);
}

int getValue() {  
  int i = (rand() % 10);
  if (i == 0) {
    return 0;
  } 
  i -= 5;
  return i >= 0 ? i : i * -1;
}

byte *getArray(int count) {
  byte *leds = (byte *)malloc(sizeof(byte) * count);
  for (int i = 0; i < count; i++) {
    leds[i] = getValue();
  }
  return leds;
}
