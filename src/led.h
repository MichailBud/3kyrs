namespace Builtin_led{

void on(){
    digitalWrite(LED_BUILTIN, HIGH);
}
void off(){
    digitalWrite(LED_BUILTIN, LOW);
}
void init(){
    pinMode(LED_BUILTIN, OUTPUT);
}}

void led_time_repeat(int time, int repeat){   // Включает светодиод на определённое время time определённое число раз repeat
    int i = repeat;
    while (i){
        i-=1;
        delay(time);
        Builtin_led::on();
        delay(time);
        Builtin_led::off();
        }
}


void delay_s(int i){
    delay(i*1000);
}

/*void led_on_time (int time){
    int duty = 0;
    time = time / 100;
    int timer = millis();
    int timer2 = 0;
    while (duty != 100){
        duty+=1;
        timer2 = millis();
        while ((millis() - timer) < time){ 
            if (){

            }
        }
        
    }
}*/