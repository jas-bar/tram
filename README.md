tram
---------------
![tram-travis-build](https://travis-ci.org/jas-bar/tram.svg?branch=master)

tram is a C++ networking & sockets library.
It is developed and tested on Linux.
tram's goal is to stay minimal in terms of dependencies, so it should be easy to port it to other platforms.

# Features & Concepts

- simple stream-like interface, but for sockets
- RAII sockets management: creating socket = connecting, destroying socket = disconnecting

## Getting Started

tram uses familiar stream-like interface for sockets.

## Connecting to server

```cpp
{
  tram::Client client("127.0.0.1", "12334");
  std::string res;
  client >> res;
  std::cout << res << std::endl;

  // client socket is closed if no other client objects are using it
}
```

## Setting up server
```cpp
{
  tram::Server server("12334");
  tram::Client conn = server.acc();

  conn << "H" << "A" << "H" << "a";

  // conn is closed
  // server is closed
}
```

# Using tram in your projects

At the moment, you have to setup includes and linking yourself.
We are working on a better way to use tram via pkgconfig.

# Licensing

tram is under MIT license. See LICENSE for more information
