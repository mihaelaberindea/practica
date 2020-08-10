#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP
#include "ClientSocket.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
class ServerSocket
{
public:
    ServerSocket(std::string address, std::size_t port);
    ~ServerSocket();

    ClientSocket accept();

private:
    std::size_t m_fd;
    std::string m_address;
    std::string m_port;
};

#include "ServerSocket.cpp"
#endif //SERVERSOCKET_HPP