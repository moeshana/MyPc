#include <IRremote.h>

#define IR_PIN 11

IRrecv IR(IR_PIN);
decode_results cmd;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IR.decode(&cmd)) {
    IR.resume();
    unsigned long val = cmd.value;
    if (val != 0xffffffff && val != 0xff) {
      Serial.print(cmd.value);
      Serial.print(" : ");
      Serial.println(cmd.value, HEX);
      Serial.println(getCommand(cmd.value));
    }
  }
  delay(1000);
 
}
