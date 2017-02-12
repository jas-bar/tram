#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include <sys/socket.h>
#include <sys/types.h>

namespace tram {
class Client;

class Socket {
  friend class tram::Client;
  const int m_socket_desc;
public:
  Socket(int domain, int type, int protocol = 0);
  Socket(int socket_desc);
  ~Socket();
};
}

#endif //__SOCKET_HPP__
