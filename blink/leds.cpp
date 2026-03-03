#include "leds.h"

void LED_MODULE::set_active(bool mod){this->active = mod;}
void LED_MODULE::set_numer_led(int led){this->numer_led = led;}
void LED_MODULE::set_rgb_color(QColor new_color){this->color = new_color;}
void LED_MODULE::set_label_ptr(QLabel* ptr){this->label = ptr;}
bool LED_MODULE::get_active_status(){return this->active;}
QLabel* LED_MODULE::get_qlabel_ptr(){return this->label;}

quint8 LED_MODULE::NUM_OF_LEDS = 7;

int LED_MODULE::get_current_red(){
    return this->color.red();
}

int LED_MODULE::get_current_green(){
    return this->color.green();
}

int LED_MODULE::get_current_blue(){
    return this->color.blue();
}

