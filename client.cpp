#include "client.hpp"
#include <netdb.h>

using namespace tram;

Client::Client(int socket_desc) : m_socket_ptr(std::make_shared<Socket>(socket_desc)) {}

Client::Client(const std::string& address, const std::string& port) : m_socket_ptr(std::make_shared<Socket>(AF_INET, SOCK_STREAM, 0)) {
  struct addrinfo *address_struct;
  getaddrinfo(address.c_str(), port.c_str(), 0, &address_struct);
  if (connect(*m_socket_ptr, address_struct->ai_addr, address_struct->ai_addrlen) == -1) {
    freeaddrinfo(address_struct);
    throw std::runtime_error(strerror(errno));
  }

  freeaddrinfo(address_struct);
}
