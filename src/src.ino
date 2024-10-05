#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

void setup(){
    Builtin_led::init();
}

void loop(){
    Builtin_led::on();
    delay_s(HALF_PERIOD);
    Builtin_led::off();
    delay_s(HALF_PERIOD);

    }
