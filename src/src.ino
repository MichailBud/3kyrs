#include "Tone.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

Tone tone1;
//using RGB = RGB_LED<12, 11, 10, 9>;

void setup(){
    tone1.begin(11);
}


int i = 400;

void loop(){
    for (i; i < 800; i++){
        tone1.play(i);
        delay(1);
    }
    for (i; i > 400; i--){
        tone1.play(i);
        delay(1);
    }
    }


