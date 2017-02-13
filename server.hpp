#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <string>
#include <vector>
#include <memory>
#include "socket.hpp"
#include "client.hpp"

namespace tram {
class Server {
  const Socket m_socket;
  std::vector<std::unique_ptr<Socket>> connections;
public:
  Server(const std::string& port);
  Client acc();
};
}

#endif //__SERVER_HPP__
