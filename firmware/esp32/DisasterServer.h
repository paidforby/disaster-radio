#ifndef DISASTERSERVER_H
#define DISASTERSERVER_H

#include <Arduino.h>
#include <cstddef>

#include "DisasterClient.h"

#define DATAGRAM_HEADER 5
#define DATAGRAM_MESSAGE 239

struct Datagram {
    uint8_t destination[4];
    uint8_t type; // 1 byte (typically a char) corresponding to intended client/service 
    uint8_t message[DATAGRAM_MESSAGE]; // content of message, possibly binary data, not necessarily null-terminated
};

class DisasterClient;

class DisasterServer
{
public:
    virtual DisasterClient* connect(DisasterClient *client) = 0;
    virtual void disconnect(DisasterClient *client) = 0;

    virtual void setup() = 0;
    virtual void loop() = 0;

    virtual void transmit(DisasterClient *client, struct Datagram datagram, size_t len) = 0;
};

#endif
