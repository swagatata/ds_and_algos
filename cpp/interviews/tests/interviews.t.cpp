#include <vector>
#include <gtest/gtest.h>
#include "interviews.h"

TEST(InterviewsTest, SampleTest) {
    EXPECT_NEAR(1.0, 1.01, 0.10);

    EXPECT_FLOAT_EQ(1.0, 1.0000000001);

    EXPECT_ANY_THROW(throw "");
}

/**
 * @brief Given an array of positive integers arr[] and an integer x, The task is to find all unique combinations in arr[] where the sum is equal to x.
 * 
 */
TEST(InterviewsTest, CombinatorialSum) {
    std::vector<u_int32_t> v{1, 2, 3, 4};
    CombinatorialSum cSum(v);
    EXPECT_EQ(cSum.uniqueSumCombinations(1), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}