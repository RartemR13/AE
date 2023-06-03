#include <gtest/gtest.h>

#include "../../src/primitive/BytesArray.hpp"

#include <cstring>
#include <cstdlib>

TEST(BytesArray, TestSize) {
    BytesArray<6> foo;
    EXPECT_EQ(sizeof(foo), 6);
}

TEST(BytesArray, TestStartStorage) {
    BytesArray<10> foo;
    
    uint8_t bytes[10];
    for (int i = 0; i < 10; ++i) {
        bytes[i] = 0;
    }
    
    ASSERT_TRUE(std::memcmp(&foo, bytes, 10) == 0);
}