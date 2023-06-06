#include <gtest/gtest.h>

#include "../../src/primitive/BytesArray.hpp"

TEST(BytesArray, TestSize) {
    ae::primitive::BytesArray<6> foo;
    EXPECT_EQ(sizeof(foo), 6);
}

TEST(BytesArray, TestStartStorage) {
    ae::primitive::BytesArray<10> foo;
    
    uint8_t bytes[10] = {};
    ASSERT_TRUE(std::memcmp(&foo, bytes, 10) == 0);
}

TEST(BytesArray, TestCopyConstructor) {
    ae::primitive::BytesArray<4> foo1;
    
    uint8_t bytes[4] = {1, 2, 3, 4};
    std::memcpy(&foo1, bytes, 4);

    ae::primitive::BytesArray<4> foo2(foo1);
    ASSERT_TRUE(std::memcmp(&foo2, bytes, 4) == 0);
}

TEST(BytesArray, TestCopyOperator) {
    ae::primitive::BytesArray<4> foo1;

    uint8_t bytes[4] = {1, 2, 3, 4};
    std::memcpy(&foo1, bytes, 4);

    auto foo2 = foo1;
    ASSERT_TRUE(std::memcmp(&foo2, bytes, 4) == 0);
}

TEST(BytesArray, TestInitilizerList) {
    ae::primitive::BytesArray<4> foo = {1, 2, 3, 4};
    
    uint8_t bytes[4] = {1, 2, 3, 4};
    ASSERT_TRUE(std::memcmp(&foo, bytes, 4) == 0);

    auto thrower = [] {
        ae::primitive::BytesArray<3> who_throw{1, 2, 3, 4};
    };
    ASSERT_THROW(thrower(), std::invalid_argument);
}

TEST(BytesArray, TestCompareOperator) {
    auto foo1 = ae::primitive::BytesArray<4>{1, 2, 3, 4};
    auto foo2 = foo1;

    ASSERT_TRUE(foo1 == foo2);
}