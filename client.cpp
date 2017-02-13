#include "client.hpp"
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <stdexcept>
#include <iostream>

using namespace tram;

Client::Client(const std::string& address, const std::string& port) : m_socket(Socket(AF_INET, SOCK_STREAM, 0)) {
  struct addrinfo *address_struct;
  getaddrinfo(address.c_str(), port.c_str(), 0, &address_struct);
  if (connect(m_socket, address_struct->ai_addr, address_struct->ai_addrlen) == -1) {
    freeaddrinfo(address_struct);
    throw std::runtime_error("Failed to connect");
  }

  freeaddrinfo(address_struct);
}

void Client::write(const char* data, const size_t& length) {
  if (send(m_socket, data, length, 0) == -1) {
    throw std::runtime_error("Failed to send data");
  }
}

void Client::operator<<(const std::string& data) {
  write(data.c_str(), data.length());
}

std::vector<char> Client::read() {
  int len = 0;
  ioctl(m_socket, FIONREAD, &len);
  if (len == 0) {
    return std::vector<char>();
  }
  std::cout << len << std::endl;
  /*char buf[len];
  if (recv(m_socket, buf, len, 0) == -1) {
    throw std::runtime_error("Failed to recieve data");
  }
  return std::vector<char>(buf, buf+len);*/
}
