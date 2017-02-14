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
  Client& operator<<(const std::string& data);
  Client& operator>>(std::string& result);
  std::string read_str() const;

  template<typename T>
  std::vector<T> read() const {
    int len = 0;
    ioctl(*m_socket_ptr, FIONREAD, &len);
    if (len == 0) {
      return std::vector<T>();
    }
    std::vector<T> result(len / sizeof(T));
    if (recv(*m_socket_ptr, result.data(), len, 0) == -1) {
      throw std::runtime_error(strerror(errno));
    }
    return result;
  }

  template<typename T>
  void write(const T& data, size_t length) {
    if (send(*m_socket_ptr, data, length * sizeof(*data), 0) == -1) {
      throw std::runtime_error(strerror(errno));
    }
  }

  template<typename T>
  void write(const std::vector<T>& data) {
    write(data.data(), data.size()); 
  }

  void write(const std::string& data) {
    write(data.data(), data.length()); 
  }

  template<typename T, size_t N>
  void write(T const (&data)[N]) {
    write(data, N);
  }
};
}

#endif //__CLIENT_HPP__
