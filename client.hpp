#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include <vector>
#include <memory>
#include "socket.hpp"

namespace tram {
class Client {
  friend class Server;
  std::shared_ptr<Socket> m_socket_ptr;
  Client(int socket_desc) : m_socket_ptr(std::make_shared<Socket>(socket_desc)) {}
public:
  Client(const std::string& address, const std::string& port);
  void write(const char* data, const size_t& length);
  void operator<<(const std::string& data);
  std::vector<char> read();
};
}

#endif //__CLIENT_HPP__
