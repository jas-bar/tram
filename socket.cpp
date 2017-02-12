#include "socket.hpp"
#include <unistd.h>
#include <stdexcept>

using namespace tram;

Socket::Socket(int domain, int type, int protocol)
  : m_socket_desc(socket(domain, type, protocol)) {
  if (m_socket_desc == -1) {
    throw std::runtime_error("Failed to create socket");
  }
}

Socket::~Socket() {
  close(m_socket_desc);
}

Socket::connect() {
  connect()
}
