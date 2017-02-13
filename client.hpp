#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include <vector>
#include "socket.hpp"

namespace tram {
class Client {
  const Socket m_socket;
public:
  Client(const std::string& address, const std::string& port);
  Client(Socket socket) : m_socket(socket) {}
  void write(const char* data, const size_t& length);
  void operator<<(const std::string& data);
  std::vector<char> read();
};
}

#endif //__CLIENT_HPP__
