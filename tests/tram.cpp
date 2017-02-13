#include "../tram.hpp"
#include <gtest/gtest.h>

TEST(tram, connect) {
    tram::Server server("10000");
    ASSERT_NO_THROW(tram::Client("127.0.0.1", "10000"));
}
