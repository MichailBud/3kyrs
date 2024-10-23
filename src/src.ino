#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using Builtin_LED = LED<13>;


void setup(){
    Serial.begin(115200);
    Builtin_LED::init();
}

void loop(){
    Builtin_LED::on();
    delay_s(PERIOD);
    Builtin_LED::off();
    delay_s(PERIOD);
    }
