#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include "socket.hpp"

namespace tram {
class Client {
  const Socket m_socket;
public:
  Client(const std::string& address, const std::string& port);
  void write(const char* data, const size_t& length);
};
}

#endif //__CLIENT_HPP__
