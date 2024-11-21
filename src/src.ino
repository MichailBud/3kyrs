#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using RGB = RGB_LED<12, 11, 10, 9>;

void setup(){
    RGB::init();
}

void loop(){
   RGB::red_on();
   RGB::green_on();
   RGB::red_off();
   RGB::green_off();

    }


