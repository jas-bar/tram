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
  Client(int socket_desc);
public:
  Client(const std::string& address, const std::string& port);
  void write(const char* data, const size_t& length);
  Client& operator<<(const std::string& data);
  Client& operator>>(std::string& result);
  std::vector<char> read();
  std::string read_str();
};
}

#endif //__CLIENT_HPP__
