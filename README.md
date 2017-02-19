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
Tram can install to `/usr/include` and `/usr/lib` directories. It also installs a `.pc` file to be usable with [pkgconfig](https://people.freedesktop.org/~dbn/pkg-config-guide.html#using) tool. It is, however, **not** required to use pkgconfig to link against tram.
```
$ git clone https://github.com/jas-bar/tram
$ cd tram
$ cmake .
$ make
$ sudo make install
```

Tram should now be available to you via pkgconfig.
If you are using CMake to build your project, you add this snippet to your `CMakeLists.txt`:
```
include(FindPkgConfig)
pkg_search_module(TRAM REQUIRED tram)
```
After this, `${TRAM_LIBRARIES}` and `${TRAM_INCLUDE_DIRS}` variables are defined, which can be utilized with `target_link_libraries` and `include_directories` respectively.
If everything is setup right, use `#include <tram/tram.hpp>` in your sources and you're ready to start coding.

For more information about this process, see pull request #12.

# Licensing

tram is under MIT license. See LICENSE for more information
