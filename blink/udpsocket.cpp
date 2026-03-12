#include "udpsocket.h"

UdpSocket::UdpSocket(){}

void UdpSocket::create_socket(){
    this->fileDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
}

void UdpSocket::set_sockaddr(QString addrIPv4, int Host){
    this->addressIPv4.sin_family = AF_INET;
    this->addressIPv4.sin_port = qToBigEndian(Host);
    this->addressIPv4 = {}; //0
    this->socketStatus = inet_pton(
        AF_INET,
        addrIPv4.toUtf8().constData(),
        &(this->addressIPv4.sin_addr));
}

ssize_t UdpSocket::sendMessage(std::vector<LED_MODULE> leds){
    QByteArray prepare_data;
    prepare_data.append(static_cast<char>(1111));
    prepare_data.append(static_cast<char>(LED_MODULE::NUM_OF_LEDS));
    for(int i=0; i<LED_MODULE::NUM_OF_LEDS; i++){
        prepare_data.append(static_cast<char>(leds[i].get_current_red()));
        prepare_data.append(static_cast<char>(leds[i].get_current_green()));
        prepare_data.append(static_cast<char>(leds[i].get_current_blue()));
    }
    prepare_data.append(static_cast<char>(1111));
    return sendto(this->fileDescriptor,
                  prepare_data.constData(),
                  prepare_data.length(),
                  0,
                  (const struct sockaddr*)&(this->addressIPv4),
                  sizeof(this->addressIPv4));
}
