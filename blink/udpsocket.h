#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <QString>
#include <QHostAddress>
#include <QtEndian>

#include <leds.h>

class UdpSocket
{
private:
    int fileDescriptor; //Numer gniazda;
    int socketStatus;
    struct sockaddr_in {
        sa_family_t sin_family;
        in_port_t sin_port;
        struct in_addr sin_addr;
        unsigned char sin_zero[8];
    } addressIPv4;

public:
    UdpSocket();
    void create_socket();
    void set_sockaddr(QString addrIPv4, int Host);
    ssize_t sendMessage(std::vector<LED_MODULE> leds);
};

#endif // UDPSOCKET_H
