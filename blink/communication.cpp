#include "communication.h"


void CONNECTION::send_message(std::vector<LED_MODULE> leds){
    QByteArray prepare_data;
    prepare_data.append(static_cast<char>(1111));
    prepare_data.append(static_cast<char>(LED_MODULE::NUM_OF_LEDS));
    for(int i=0; i<LED_MODULE::NUM_OF_LEDS; i++){
        prepare_data.append(static_cast<char>(leds[i].get_current_red()));
        prepare_data.append(static_cast<char>(leds[i].get_current_green()));
        prepare_data.append(static_cast<char>(leds[i].get_current_blue()));
    }
    prepare_data.append(static_cast<char>(1111));
    qint64 result = this->UDP->writeDatagram(prepare_data, this->ADDR, this->port);
    qDebug() << result;
}


void CONNECTION::set_host(QString host){
    this->ADDR.setAddress(host);
}

void CONNECTION::set_port(quint16 port){
    this->port = port;
}

QHostAddress CONNECTION::get_host(){
    return this->ADDR;
}

quint16 CONNECTION::get_port(){
    return this->port;
}
