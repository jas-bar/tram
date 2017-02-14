#include "../client.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(Client, constuctor1) {
    ASSERT_THROW(tram::Client("127.0.0.1", "30000"), std::runtime_error);
}

TEST(Client, constuctor2) {
    ASSERT_THROW(tram::Client("127.0.0.1", "9999"), std::runtime_error);
}
