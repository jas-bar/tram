#include "../tram.hpp"
#include <gtest/gtest.h>

TEST(tram, connect) {
    tram::Server server("10000");
    ASSERT_NO_THROW(tram::Client("127.0.0.1", "10000"));
}

TEST(tram, accept) {
    tram::Server server("10001");
    tram::Client client("127.0.0.1", "10001");
    tram::Client conn = server.acc();
}

TEST(tram, sendAndReceive) {
    tram::Server server("10002");
    tram::Client client("127.0.0.1", "10002");
    tram::Client conn = server.acc();
    conn << "Hi world!";
    ASSERT_EQ("Hi world!", client.read_str());
}
