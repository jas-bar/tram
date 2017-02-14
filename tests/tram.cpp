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

TEST(tram, sendAndReceiveUInt32Vector) {
    tram::Server server("10006");
    tram::Client client("127.0.0.1", "10006");
    tram::Client conn = server.acc();
    std::vector<uint32_t> numbers {1, 2, 3, 4};
    conn.write(numbers);
    std::vector<uint32_t> recv = client.read<uint32_t>();
    ASSERT_EQ(numbers, recv);
}

TEST(tram, sendAndReceiveLongLongArray) {
    tram::Server server("10007");
    tram::Client client("127.0.0.1", "10007");
    tram::Client conn = server.acc();
    long long numbers[] = {1, 2, 3, 4};
    conn.write(numbers);
    std::vector<long long> recv = client.read<long long>();
    ASSERT_EQ(4, recv.size());
    ASSERT_EQ(1, recv[0]);
    ASSERT_EQ(2, recv[1]);
    ASSERT_EQ(3, recv[2]);
    ASSERT_EQ(4, recv[3]);
}

TEST(tram, sendAndReceiveLongLongVector) {
    tram::Server server("10008");
    tram::Client client("127.0.0.1", "10008");
    tram::Client conn = server.acc();
    std::vector<long long> numbers {1, 2, 3, 4};
    conn.write(numbers);
    std::vector<long long> recv = client.read<long long>();
    ASSERT_EQ(numbers, recv);
}

struct TestStruct1 {
    int n;
    char c;
};

TEST(tram, sendAndReceiveStruct) {
    tram::Server server("10009");
    tram::Client client("127.0.0.1", "10009");
    tram::Client conn = server.acc();
    TestStruct1 ts {42, 'a'};
    conn.write(&ts, 1);
    std::vector<TestStruct1> recv = client.read<TestStruct1>();
    ASSERT_EQ(ts.n, recv[0].n);
    ASSERT_EQ(ts.c, recv[0].c);
}
