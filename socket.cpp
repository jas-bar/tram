#include "socket.hpp"
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>

using namespace tram;

Socket::Socket(int domain, int type, int protocol)
  : Socket(socket(domain, type, protocol)) {}

Socket::Socket(int socket_desc) : m_socket_desc(socket_desc) {
  if (m_socket_desc == -1) {
    throw std::runtime_error(strerror(errno));
  }
}

Socket::~Socket() {
  close(m_socket_desc);
}
