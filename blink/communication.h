#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QUdpSocket>
#include "leds.h"
#include <QByteArray>
#include <QHostAddress>

class CONNECTION{

private:
    QUdpSocket *UDP;
    QHostAddress ADDR;
    quint16 port;
    bool connect_status;
public:
    void send_message(std::vector<LED_MODULE> leds);
    void set_host(QString host);
    void set_port(quint16 port);
    void set_data(bool status);
    bool get_data_status();

    QHostAddress get_host();
    quint16 get_port();

    CONNECTION(){
        this->UDP = new QUdpSocket();
    }
    ~CONNECTION(){
        delete this->UDP;
    }

};

#endif // COMMUNICATION_H
