#include <vector>
#include <gtest/gtest.h>
#include "atlassian.h"

TEST(AtlassianTest, SampleTest) {
    FileSystem fileSystem;

    fileSystem.addFile(100);
    fileSystem.addFile(200, 1);
    fileSystem.addFile(200, 1);
    fileSystem.addFile(300, 2);
    fileSystem.addFile(10);
    // std::cout << "test" << std::endl;

    EXPECT_EQ(fileSystem.totalSize(), 810);
    // std::cout << "first test";

    auto top1 = fileSystem.topCollections(1);
    EXPECT_EQ(top1.size(), 1);
    EXPECT_EQ(top1[0], 1);
    // std::cout << "second test" << std::endl;

    auto top3 = fileSystem.topCollections(3);
    EXPECT_EQ(top3.size(), 2);
    EXPECT_EQ(top3[0], 1);
    EXPECT_EQ(top3[1], 2);
}

/**
 * @brief Given an array of positive integers arr[] and an integer x, The task is to find all unique combinations in arr[] where the sum is equal to x.
 * 
 */

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}