#include <gtest/gtest.h>

// Example function to test
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(-10, -20), -30);
}

TEST(AddTest, MixedNumbers) {
    EXPECT_EQ(add(-2, 3), 1);
    EXPECT_EQ(add(10, -20), -10);
} 