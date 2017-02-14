#include "../tram.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(tram, connect) {
    tram::Server server("10000");
    ASSERT_NO_THROW(tram::Client("127.0.0.1", "10000"));
}

TEST(tram, accept) {
    tram::Server server("10001");
    tram::Client client("127.0.0.1", "10001");
    tram::Client conn = server.acc();
}

TEST(tram, sendAndReceiveStr) {
    tram::Server server("10002");
    tram::Client client("127.0.0.1", "10002");
    tram::Client conn = server.acc();
    conn << "Hi world!";
    ASSERT_EQ("Hi world!", client.read_str());
}

TEST(tram, sendAndReceiveCStr) {
    tram::Server server("10003");
    tram::Client client("127.0.0.1", "10003");
    tram::Client conn = server.acc();
    conn.write("Ahoj", 4);
    ASSERT_EQ("Ahoj", client.read_str());
}

TEST(tram, sendAndReceiveChar) {
    tram::Server server("10004");
    tram::Client client("127.0.0.1", "10004");
    tram::Client conn = server.acc();
    conn.write(std::string("Hi"));
    ASSERT_EQ(2, client.read<char>().size());
}

TEST(tram, sendAndReceiveInt) {
    tram::Server server("10005");
    tram::Client client("127.0.0.1", "10005");
    tram::Client conn = server.acc();
    int numbers[] = {1, 2, 3, 4};
    conn.write(numbers);
    ASSERT_EQ(4, client.read<int>().size());
}

TEST(tram, sendAndReceiveVector) {
    tram::Server server("10006");
    tram::Client client("127.0.0.1", "10006");
    tram::Client conn = server.acc();
    std::vector<uint32_t> numbers {1, 2, 3, 4};
    conn.write(numbers);
    std::vector<uint32_t> recv = client.read<uint32_t>();
    ASSERT_EQ(numbers, recv);
}
