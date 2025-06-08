#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

struct StrRef {
    const string& str;
    size_t l, r;

    size_t length() {
        return r - l;
    }

    bool empty() {
        return str.empty() or l == r;
    }

    char operator[](size_t index) {
        if (index < l || index >= r) {
            // cerr << "Index out of range " << str << ":" << index << '\n';
        }
        return str[index];
    }

    bool operator==(const StrRef& other) {
        // cout << "comparing strings : "; print(); other.print(); cout << endl;
        if (r - l != other.r - other.l) {
            return false;
        }
        for (auto i = 0; i + l < r; ++i) {
            if (str[l + i] != other.str[other.l + i]) {
                return false;
            }
        }
        return true;
    }

    StrRef(const string& strin, size_t lp, size_t rp) : str(strin), l(lp), r(rp) {}

    void print() const {
        cout << "string is: ";
        for (auto i = l; i < r; ++i) {
            cout << str[i] << ",";
        }
    }
};

// Function to find indices where two strings differ
// Returns a vector of indices where the characters differ
vector<size_t> findDiffIndex(StrRef s1, StrRef s2) {
    // cout << "comparing "; s1.print(); cout << " and "; s2.print(); cout << endl;
    if (s1.length() != s2.length() + 1)
        return {};
    
    if (s2.empty())
        return {0};

    static vector<

    vector<size_t> diffIndices;
    if (s1[s1.l] == s2[s2.l]) {
        auto s1Right = s1;
        auto s2Right = s2;
        s1Right.l++;
        s2Right.l++;
        diffIndices = findDiffIndex(s1Right, s2Right);
        for (auto& i : diffIndices) {
            i++;
        }
    }
    s1.l++;    
    if (s1 == s2) {
        diffIndices.insert(diffIndices.begin(), 0);
    }
    return diffIndices;
}

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
    StrRef str1(s1, 0, s1.size());
    StrRef str2(s2, 0, s2.size());
    EXPECT_EQ(findDiffIndex(str1, str2), expected);
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