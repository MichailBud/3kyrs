#include "led.h"
#include <type_traits>
#include <iostream>

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using Builtin_LED = LED<13, Anode_driven>;
using RGB = RGB_LED<8, 9, 10, 11, Cathode_driven>;


void setup(){
    Serial.begin(115200);
    RGB::init();
    Builtin_LED::init();
}

void loop(){
    RGB::blue_on();
    }
