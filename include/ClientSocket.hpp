#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP
#include "ClientSocket.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
class ClientSocket
{
public:
    ClientSocket(std::string address, std::size_t port);
    ~ClientSocket();

    operator bool();
    bool connect();

    void send(std::vector<std::byte> message);
    void receive(std::vector<std::byte> message);

private:
    std::size_t m_fd;
};

#include "ClientSocket.cpp"
#endif //CLIENTSOCKET_HPP