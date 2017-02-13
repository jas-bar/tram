#include "server.hpp"
#include <stdexcept>
#include <netinet/in.h>
#include <string.h>

using namespace tram;

Server::Server(const std::string& port) : m_socket(Socket(AF_INET, SOCK_STREAM, 0)) {
  struct sockaddr_in address_struct;
  bzero((char *) &address_struct, sizeof(address_struct));
  address_struct.sin_family = AF_INET;
  address_struct.sin_addr.s_addr = INADDR_ANY;
  address_struct.sin_port = htons(stoi(port));
  if (bind(m_socket, (struct sockaddr *) &address_struct, sizeof(address_struct)) == -1) {
    throw std::runtime_error("Failed to bind socket");
  }
  if (listen(m_socket, 5) == -1) {
    throw std::runtime_error("Failed to listen on socket");
  }
}

Client Server::acc() {
  struct sockaddr_in cli_addr;
  unsigned int cli_addr_len = sizeof(cli_addr);
  int client_socket = 0;

  if ((client_socket = accept(m_socket,
          (struct sockaddr *) &cli_addr,
          &cli_addr_len)) == -1) {
    throw std::runtime_error("Failed to accept connection");
  }

  return Client(Socket(client_socket));
}
