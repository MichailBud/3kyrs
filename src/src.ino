#include "Tone.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

Tone tone1;
//using RGB = RGB_LED<12, 11, 10, 9>;

void setup(){
    tone1.begin(11);
    pinMode(A1, INPUT);
    Serial.begin(9600);
}




void loop(){
    tone1.play(analogRead(A1));
    Serial.println(analogRead(A1));
    }


