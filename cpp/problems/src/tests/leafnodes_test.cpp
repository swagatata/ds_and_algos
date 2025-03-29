#include <gtest/gtest.h>
#include <vector>
#include <cmath>
using namespace std;

void leafNodes(vector<int> &tree, vector<int> &result) {
    if (tree.empty()) {
        return;
    }
    if (tree.size() == 1) {
        result.push_back(tree.back());
        tree.pop_back();
        return;
    }
    int nLeafNodes = (tree.size() + 1) / 2;
    int powerOf2LessThanTreeSize = 1 << (int)log2(tree.size() + 1);
    int count = 0;
    for (int i = powerOf2LessThanTreeSize - 1; i < tree.size(); i++) {        
        result.push_back(tree[i]);
        count++;
    }
    tree.resize(tree.size() - count);
    int remaining = nLeafNodes - count;
    int start_i = tree.size() - remaining;
    for (int i = start_i; i < tree.size(); i++) {
        result.push_back(tree[i]);
    }
    tree.resize(start_i);
}

vector<int> allLeafNodes(vector<int> &tree) {
    vector<int> result;
    while (!tree.empty()) {
        leafNodes(tree, result);
    }
    return result;
}

class LeafNodesPTest : public ::testing::TestWithParam<pair<vector<int>, vector<int>>> {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }
};

TEST_P(LeafNodesPTest, DifferentTreeSizes) {
    auto tree = GetParam().first;
    auto leafs = allLeafNodes(tree);
    auto &expected = GetParam().second;
    EXPECT_EQ(leafs.size(), expected.size());
    for (int i = 0; i < leafs.size(); i++) {
        EXPECT_EQ(leafs[i], expected[i]);
    }
}

INSTANTIATE_TEST_SUITE_P(LeafNodesPTest, LeafNodesPTest, ::testing::Values(
    // Empty tree
    make_pair(vector<int>{}, vector<int>{}),
    
    // Single node tree
    make_pair(vector<int>{1}, vector<int>{1}),
    
    // Two node tree
    make_pair(vector<int>{1, 2}, vector<int>{2, 1}),
    
    // Three node tree
    make_pair(vector<int>{1, 2, 3}, vector<int>{2, 3, 1}),
    
    // Four node tree
    make_pair(vector<int>{1, 2, 3, 4}, vector<int>{4, 3, 2, 1}),
    
    // Five node tree
    make_pair(vector<int>{1, 2, 3, 4, 5}, vector<int>{4, 5, 3, 2, 1}),
    
    // Seven node tree
    make_pair(vector<int>{1, 2, 3, 4, 5, 6, 7}, vector<int>{4, 5, 6, 7, 2, 3, 1}),
    
    // Eight node tree
    make_pair(vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, vector<int>{8, 5, 6, 7, 4, 3, 2, 1})
));

