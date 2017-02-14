#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include "socket.hpp"

namespace tram {
class Client {
  friend class Server;
  std::shared_ptr<Socket> m_socket_ptr;
  Client(int socket_desc);
public:
  Client(const std::string& address, const std::string& port);

  template<typename T>
  friend Client& operator>>(Client& client, std::vector<T>& result) {
    int len = 0;
    ioctl(*client.m_socket_ptr, FIONREAD, &len);
    result.clear();
    result.resize(len / sizeof(T));
    if (recv(*client.m_socket_ptr, result.data(), len, 0) == -1) {
      throw std::runtime_error(strerror(errno));
    }
    return client;
  }
  template <typename T>
  friend Client& operator>>(Client& client, T& result) {
    if (recv(*client.m_socket_ptr, result, sizeof(*result), 0) == -1) {
      throw std::runtime_error(strerror(errno));
    }
    return client;
  }

  friend Client& operator>>(Client& client, std::string& result) {
    result.clear();
    std::vector<char> temp;
    client >> temp;
    result = temp.data();
    return client;
  }

  template<typename T>
  void write(const T& data, size_t length) {
    if (send(*m_socket_ptr, data, length * sizeof(*data), 0) == -1) {
      throw std::runtime_error(strerror(errno));
    }
  }

  template<typename T>
  friend Client& operator<<(Client& client, const T& data) {
      client.write(data, sizeof(*data)); 
      return client;
  }

  template<typename T>
  friend Client& operator<<(Client& client, const std::vector<T>& data) {
      client.write(data.data(), data.size()); 
      return client;
  }


  friend Client& operator<<(Client& client, const std::string& data) {
    client.write(data.c_str(), data.length() + 1); 
    return client;
  }

  friend Client& operator<<(Client& client, const char *const data) {
    client.write(data, strlen(data) + 1);
    return client;
  }

  template<typename T, size_t N>
  friend Client& operator<<(Client& client, T const (&data)[N]) {
    client.write(data, N);
    return client;
  }
};
}

#endif //__CLIENT_HPP__
