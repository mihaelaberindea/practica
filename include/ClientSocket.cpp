#include "ClientSocket.hpp"

ClientSocket::ClientSocket(std::string address, std::size_t port)
{

}
ClientSocket::~ClientSocket()
{

}

ClientSocket::operator bool()
{  
 return m_fd != 0; 
}

bool ClientSocket::connect()
{

}

void ClientSocket::send(std::vector<std::byte> message)
{

}
void ClientSocket::receive(std::vector<std::byte> message)
{

}