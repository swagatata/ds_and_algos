#include <gtest/gtest.h>
#include "interviews.h"

TEST(InterviewsTest, SampleTest) {
    DistributedSystem system;
    EXPECT_NEAR(1.0, 1.01, 0.10);

    EXPECT_FLOAT_EQ(1.0, 1.0000000001);

    EXPECT_ANY_THROW(throw "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}