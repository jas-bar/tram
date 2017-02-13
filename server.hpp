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
public:
  Server(const std::string& port);
  Server(const Server& other) = delete;
  Server(Server& other) = delete;
  Client acc();
};
}

#endif //__SERVER_HPP__
