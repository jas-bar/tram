#include <iostream>
#include "server.hpp"
#include "client.hpp"

int main() {
  tram::Server server("12334");
  tram::Client client("127.0.0.1", "12334");
  tram::Client conn = server.acc();
  conn << "H" << "A" << "H" << "a";
  std::string res;
  client >> res;
  std::cout << res << std::endl;
}
