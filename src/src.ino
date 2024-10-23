#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using Builtin_LED = LED<13>;
using RGB = RGB_LED<8, 9, 10, 11>;


void setup(){
    Serial.begin(115200);
    RGB::init();
    Builtin_LED::init();
}

void loop(){
    RGB::smooth_on(1500);
    RGB::smooth_off(1500);
    }
