#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Problem {
private:
  const string& s1;
  const string& s2;
  size_t commonSuffixSize;
public:
  Problem(const string& str1, const string& str2) : s1(str1), s2(str2) {

  }

  void computeSuffix() {
    size_t s1size = s1.size();
    size_t s2size = s2.size();
    size_t i;
    for (i = 1; s2size >= i && s1[s1size - i] == s2[s2size - i]; ++i) {}
    commonSuffixSize = i - 1;
  }

  stack<size_t> computeDiff(size_t i1, size_t i2) {
    // cout << "computing with " << i1 << " and " << i2 << endl;
    stack<size_t> possibleDiffs;  
    if (i2 == s2.size()) {
      possibleDiffs.push(i1);
      return possibleDiffs;
    }

    // compute
    if (s1[i1] == s2[i2]) {
      possibleDiffs = computeDiff(i1+1, i2+1);
    }

    // common prefix
    if (commonSuffixSize > 0 && i1 + 1 + commonSuffixSize >= s1.size()) {
      possibleDiffs.push(i1);
    }
    return possibleDiffs;
  }

  vector<size_t> solution() {
    // cout << "finding solution for " << s1 << " and " << s2 << endl;
    if (s1.size() != s2.size() + 1) {
      return {};
    }

    computeSuffix();
    // cout << "common suffix is " << commonSuffixSize << endl;
    auto diffIndices = computeDiff(0, 0);
    vector<size_t> v;
    while(!diffIndices.empty()) {
      v.push_back(diffIndices.top());
      diffIndices.pop();
    }
    return v;
  }
};


// Parameterized test for different string pairs
class DiffOneStringsPTest : public ::testing::TestWithParam<tuple<string, string, vector<size_t>>> {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

TEST_P(DiffOneStringsPTest, DifferentCases) {
    auto [s1, s2, expected] = GetParam();
    // StrRef str1(s1, 0, s1.size());
    // StrRef str2(s2, 0, s2.size());
    Problem p(s1, s2);
    // EXPECT_EQ(findDiffIndex(str1, str2), expected);
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
