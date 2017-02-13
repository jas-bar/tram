#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include <sys/socket.h>
#include <sys/types.h>

namespace tram {
class Socket {
  const int m_socket_desc;
public:
  Socket(int domain, int type, int protocol = 0);
  Socket(int socket_desc);
  Socket(const Socket& other) = delete;
  Socket(Socket& other) = delete;
  operator int() const { return m_socket_desc; }
  ~Socket();
};
}

#endif //__SOCKET_HPP__
