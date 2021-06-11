#include "song_note.c"
int buzz = 10;
//int scale[] = {G, A, EE, A, G, A, G, A, EE,
//               A, EE, A, G, A,  E,
//               G, D,  E, G, A,  B,
//               A, EE, A, G, A,  G,
//               A, EE, B, CC,B,  CC, B,  A,  E,
//               D, E,  G, A, B,  A,  EE, A,  G,  A,
//               G, A,  EE,A, G,  A,  EE, A,  G,  A,
//               E, G,  D, E, G,  A,  B,  A,  EE, A, G, A,
//               G, A,  EE,B, CC, B,  CC, DD, EE, AA};             
//float duration[] = {2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1,
//                    1, 1, 1, 1, 3, 1,
//                    3,1,1,1,1,1,
//                    1,1,1,1,7,1,
//                    1,1,1,1,1,1,1,1,6,
//                    1,1,1,1,1,1,1,1,1,7,
//                    1,1,1,1,1,1,1,1,1,3,
//                    1,3,1,1,1,1,1,1,1,1,7,
//                    1,1,1,1,1,1,1,1,4};

int scale[] = {G, G, G, E, F, G,
               G, B,
               A, A, A, A, F, A,
               G, 
               G, G, G, G, B, A,
               G, F,
               F, F, F, F, E, D,
               C, C};
float duration[] = {1,1,1,1,1,1,
                    3,3,
                    1,1,1,1,1,1,
                    6,
                    1,1,1,1,1,1,
                    1, 5,
                    1,1,1,1,1.5,0.5,
                    6};

int scale2[] = {CC, CC, CC, CC, G, A,
                CC, CC, EE,
                DD, DD, DD, DD, CC, B,
                A, 
                B, B, B, B, B, CC,
                DD, G,
                B,B,CC,DD,CC,B,
                CC
                };
float duration2[] = {1,1,1,1,1,1,
                    2, 1, 3,
                    1,1,1,1.5,0.5,1,
                    6,
                    1,1,1,1,1,1,
                    3,3,
                    1,1,1,1,1,1,
                    6
                    };

                    
int len = 0;
int len2 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  len = sizeof(scale) / sizeof(scale[0]);
  len2 = sizeof(scale2) / sizeof(scale2[0]);
  Serial.println(sizeof(scale) / sizeof(int));
  Serial.println(sizeof(duration) / sizeof(float));
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int y = 0; y < 2; y++) {
    for (int i = 0; i < len; i++) {
      tone(buzz, scale[i]);
      delay(250*duration[i]);
      noTone(buzz);
      delay(100);
    }
  }
  for (int i = 0; i < len2; i++) {
     tone(buzz, scale2[i]);
     delay(250*duration2[i]);
     noTone(buzz);
     delay(100);
  }
  delay(1000);
}
