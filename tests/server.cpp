#include "../server.hpp"
#include <gtest/gtest.h>

TEST(Server, constuctor) {
    ASSERT_NO_THROW(tram::Server("20000"));
}
