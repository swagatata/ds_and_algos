#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <stack>
#include "basetest.t.h"

using namespace std;

class Problem {
private:
  const string& s1;
  const string& s2;
  size_t commonSuffixSize;
public:
  Problem(const string& str1, const string& str2) : s1(str1), s2(str2) {
    DEBUG_LOG("Created Problem with strings: " << s1 << " and " << s2);
  }

  void computeSuffix() {
    size_t s1size = s1.size();
    size_t s2size = s2.size();
    size_t i;
    for (i = 1; s2size >= i && s1[s1size - i] == s2[s2size - i]; ++i) {}
    commonSuffixSize = i - 1;
    DEBUG_LOG("Common suffix size: " << commonSuffixSize);
  }

  stack<size_t> computeDiff(size_t i1, size_t i2) {
    DEBUG_LOG("Computing diff with indices: " << i1 << " and " << i2);
    stack<size_t> possibleDiffs;  
    if (i2 == s2.size()) {
      possibleDiffs.push(i1);
      DEBUG_LOG("Reached end of s2, pushing index: " << i1);
      return possibleDiffs;
    }

    // compute
    if (s1[i1] == s2[i2]) {
      DEBUG_LOG("Characters match at " << i1 << ", recursing");
      possibleDiffs = computeDiff(i1+1, i2+1);
    }

    // common prefix
    if (commonSuffixSize > 0 && i1 + 1 + commonSuffixSize >= s1.size()) {
      DEBUG_LOG("Found common prefix, pushing index: " << i1);
      possibleDiffs.push(i1);
    }
    return possibleDiffs;
  }

  vector<size_t> solution() {
    DEBUG_LOG("Finding solution for: " << s1 << " and " << s2);
    if (s1.size() != s2.size() + 1) {
      DEBUG_LOG("Strings don't differ by exactly one character");
      return {};
    }

    computeSuffix();
    auto diffIndices = computeDiff(0, 0);
    vector<size_t> v;
    while(!diffIndices.empty()) {
      v.push_back(diffIndices.top());
      diffIndices.pop();
    }
    DEBUG_LOG("Solution found with " << v.size() << " differences");
    return v;
  }
};

// Parameterized test for different string pairs
class DiffOneStringsPTest : public BaseTest, public ::testing::WithParamInterface<tuple<string, string, vector<size_t>>> {
protected:
    void SetUp() override {
        BaseTest::SetUp();  // Call parent's SetUp to initialize debug mode
    }
};

TEST_P(DiffOneStringsPTest, DifferentCases) {
    auto [s1, s2, expected] = GetParam();
    Problem p(s1, s2);
    EXPECT_EQ(p.solution(), expected);
}

INSTANTIATE_TEST_SUITE_P(
    DiffOneStringsPTest,
    DiffOneStringsPTest,
    ::testing::Values(
        make_tuple("hello", "hello", vector<size_t>{}),
        make_tuple("hello", "hell", vector<size_t>{4}),
        make_tuple("hello", "helo", vector<size_t>{2,3}),
        make_tuple("hello", "ello", vector<size_t>{0}),
        make_tuple("hello", "world", vector<size_t>{})
    )
);
