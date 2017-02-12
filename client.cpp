#include "client.hpp"
#include <netdb.h>
#include <sys/socket.h>
#include <stdexcept>

using namespace tram;

Client::Client(const std::string& address, const std::string& port) : m_socket(Socket(AF_INET, SOCK_STREAM, 0)) {
  struct addrinfo *address_struct;
  getaddrinfo(address.c_str(), port.c_str(), 0, &address_struct);
  if (connect(m_socket.m_socket_desc, address_struct->ai_addr, address_struct->ai_addrlen) == -1) {
    freeaddrinfo(address_struct);
    throw std::runtime_error("Failed to connect");
  }

  freeaddrinfo(address_struct);
}

void Client::write(const char* data, const size_t& length) {
  if (send(m_socket.m_socket_desc, data, length, 0) == -1) {
    throw std::runtime_error("Failed to send data");
  }
}
