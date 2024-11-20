#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using RGB = RGB_LED<12, 11, 10, 9>;
using Photo = Photo_R<A1>;

void setup(){
    Serial.begin(115200);
    Photo::init();
    RGB::init();
}

void loop(){
    Serial.println(analogRead(A1));
    RGB::blue_SHIM(map(analogRead(A1), 100, 700, 255, 0));
    }


