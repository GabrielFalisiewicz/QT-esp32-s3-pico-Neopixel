#ifndef LEDS_H
#define LEDS_H
#include <QLabel>
#include <QColor>



class LED_MODULE{
public:
    void set_active(bool mod);
    void set_rgb_color(QColor new_color);
    void set_numer_led(int led);
    void set_label_ptr(QLabel* ptr);
    bool get_active_status();
    int get_current_red();
    int get_current_green();
    int get_current_blue();
    QLabel* get_qlabel_ptr();
    static quint8 NUM_OF_LEDS;
private:
    QLabel* label = nullptr;
    bool active = false;
    QColor color;
    int numer_led = 0;
};

#endif // LEDS_H
