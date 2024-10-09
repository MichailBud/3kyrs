#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

unsigned int a = 1;
LED red = 13;
LED yellow = 12;
LED green = 11;


void setup(){
    red.init();
    yellow.init();
    green.init();
    Serial.begin(115200);
}

void loop(){
    red.on();
    delay(5000);
    yellow.on();
    Serial.println("Ready!");
    delay(1000);
    yellow.off();
    red.off();
    green.on();
    Serial.println("GO!");
    delay(5000);
    green.off();
    green.on_time_repeat(500, 3);
    Serial.println("Ready to stop!");
    yellow.on();
    delay(1500);
    yellow.off();
    Serial.println("STOP!");

    }
