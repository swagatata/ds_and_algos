#include <gtest/gtest.h>
#include <string>

class Problem {
public:
    int find(std::string_view text, std::string_view pattern) {
        return 0;
    }
};

TEST(FindStringTest, Basics) {
    Problem p;
    EXPECT_EQ(p.find("abcd", "a"), 0);
}