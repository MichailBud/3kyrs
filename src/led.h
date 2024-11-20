

class Anode_driven{};
class Cathode_driven{};

template<int pin, typename Conn_type>
class LED{
public:

    LED()=delete;

    static void init(){pinMode(pin, OUTPUT);}
    
    static void on(){		
        if constexpr(std::is_same<Anode_driven, Conn_type>){digitalWrite(pin, HIGH);}
		if constexpr(std::is_same<Cathode_driven, Conn_type>){digitalWrite(pin, LOW);}
        }
    
	static void off(){
		if constexpr(std::is_same<Anode_driven, Conn_type>){digitalWrite(pin, LOW);}
		if constexpr(std::is_same<Cathode_driven, Conn_type>){digitalWrite(pin, HIGH);}
	} 

    void on_time_repeat(int time, int repeat){   // Включает светодиод на определённое время time определённое число раз repeat
    int i = repeat;
    while (i){
        i-=1;
        delay(time);
        on();
        delay(time);
        off();
        }
    }
};

template<int vcc, int red, int blue, int green, typename Conn_type>
class RGB_LED{
public:
    RGB_LED(){};
    
    static void init(){
        pinMode(red, OUTPUT);
        pinMode(green, OUTPUT);
        pinMode(blue, OUTPUT);
        pinMode(vcc, OUTPUT);
        if constexpr(std::is_same<Anode_driven, Conn_type>){digitalWrite(vcc, LOW);}
		if constexpr(std::is_same<Cathode_driven, Conn_type>){digitalWrite(vcc, HIGH);}
    }

    static void red_on(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(red, HIGH);
            }
		if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(red, LOW);
            }
    }

    static void green_on(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(green, HIGH);
            }
		if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(green, LOW);
            }
    }

    static void blue_on(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(blue, HIGH);
            }
		if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(blue, LOW);
            }
    }

    static void red_off(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(red, LOW);
            }
		if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(red, HIGH);
            }
    }

    static void green_off(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(green, LOW);
            }
        if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(green, HIGH);
            }
    }

    static void blue_off(){
        if constexpr(std::is_same<Anode_driven, Conn_type>){
            digitalWrite(blue, LOW);
            }
        if constexpr(std::is_same<Cathode_driven, Conn_type>){
            digitalWrite(blue, HIGH);
            }
    }
};

class Digital_indicator{  //Класс 7 сегментного цифрового индикатора
public:
    Digital_indicator(int up, int average, int down, int l_up, int l_down, int r_up, int r_down){
        pin_up = up; 
        pin_average = average; 
        pin_down = down; 
        pin_l_up = l_up; 
        pin_l_down = l_down; 
        pin_r_up = r_up; 
        pin_r_down = r_down;
    };
    void init(){
        pinMode(pin_up, OUTPUT);
        pinMode(pin_average, OUTPUT);
        pinMode(pin_down, OUTPUT);
        pinMode(pin_l_up, OUTPUT);
        pinMode(pin_l_down, OUTPUT);
        pinMode(pin_r_up, OUTPUT);
        pinMode(pin_r_down, OUTPUT);
        }
    void off(){
        digitalWrite(pin_up, HIGH);
        digitalWrite(pin_average, HIGH);
        digitalWrite(pin_down, HIGH);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, HIGH);
        digitalWrite(pin_r_down, HIGH);
        digitalWrite(pin_r_up, HIGH);
    }
    void on(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, LOW);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);
    }
    void zero(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, HIGH);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, LOW);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);    
    }
    void one(){
        digitalWrite(pin_up, HIGH);
        digitalWrite(pin_average, HIGH);
        digitalWrite(pin_down, HIGH);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, HIGH);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);
    }
    void two(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, LOW);
        digitalWrite(pin_l_up, HIGH);
        digitalWrite(pin_r_down, HIGH);
        digitalWrite(pin_r_up, LOW);
    }
    void three(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, HIGH);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);
    }
    void four(){
        digitalWrite(pin_up, HIGH);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, HIGH);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);
    }
    void five(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, HIGH);
    }
    void six(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, LOW);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, HIGH);
    }
    void seven(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, HIGH);
        digitalWrite(pin_down, HIGH);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, HIGH);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);
    }
    void eight(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, LOW);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);        
    }
    void nine(){
        digitalWrite(pin_up, LOW);
        digitalWrite(pin_average, LOW);
        digitalWrite(pin_down, LOW);
        digitalWrite(pin_l_down, HIGH);
        digitalWrite(pin_l_up, LOW);
        digitalWrite(pin_r_down, LOW);
        digitalWrite(pin_r_up, LOW);        
    }
    void counting_down(int time){
        zero();
        delay(time);
        one();
        delay(time);
        two();
        delay(time);
        three();
        delay(time);
        four();
        delay(time);
        five();
        delay(time);
        six();
        delay(time);
        seven();
        delay(time);
        eight();
        delay(time);  
        nine();
        delay(time);  
    }

private:
    int pin_up; 
    int pin_average; 
    int pin_down; 
    int pin_l_up; 
    int pin_l_down; 
    int pin_r_up; 
    int pin_r_down;
};

namespace Builtin_led{

constexpr int LED_PIN{13};

void on(){
    digitalWrite(LED_PIN, HIGH);
}
void off(){
    digitalWrite(LED_PIN, LOW);
}
void init(){
    pinMode(LED_PIN, OUTPUT);
}
void on_time_repeat(int time, int repeat){   // Включает светодиод на определённое время time определённое число раз repeat
    int i = repeat;
    while (i){
        i-=1;
        delay(time);
        Builtin_led::on();
        delay(time);
        Builtin_led::off();
        }
}
}

namespace Led{
void init(int pin){
    pinMode(pin, OUTPUT);
}
void on(int pin){
    digitalWrite(pin, HIGH);
}
void off(int pin){
    digitalWrite(pin, LOW);
}
void on_time_repeat(int pin, int time, int repeat){   // Включает светодиод на определённое время time определённое число раз repeat
    int i = repeat;
    while (i){
        i-=1;
        delay(time);
        Led::on(pin);
        delay(time);
        Led::off(pin);
        }
}
}

void delay_s(int i){
    delay(i*1000);
}

/*void led_on_time (int time){
    int duty = 1;
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