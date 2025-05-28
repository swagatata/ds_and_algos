#include <gtest/gtest.h>
#include <memory>

using namespace std;

// Binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to delete a tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Function to find k-unbalanced node in a binary tree
// Returns nullptr if no k-unbalanced node is found
// A node is k-unbalanced if the difference in heights of its left and right subtrees is greater than k
TreeNode* findKUnbalanced(TreeNode* root, int k) {
    // TODO: Implement the function
    return nullptr;
}

// Test fixture class
class KUnbalancedTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

// Basic test case
TEST(KUnbalancedTest, BasicTest) {
    // Example tree:
    //     1
    //    / \
    //   2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    EXPECT_EQ(findKUnbalanced(root, 1), nullptr);
    
    deleteTree(root);
}

// Parameterized test
class KUnbalancedPTest : public ::testing::TestWithParam<tuple<TreeNode*, int, TreeNode*>> {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup both input and expected trees
        if (get<0>(GetParam())) {
            deleteTree(get<0>(GetParam()));
        }
        if (get<2>(GetParam())) {
            deleteTree(get<2>(GetParam()));
        }
    }
};

TEST_P(KUnbalancedPTest, DifferentCases) {
    auto root = get<0>(GetParam());
    auto k = get<1>(GetParam());
    auto expected = get<2>(GetParam());
    EXPECT_EQ(findKUnbalanced(root, k), expected);
}

// Example test cases
INSTANTIATE_TEST_SUITE_P(KUnbalancedPTest, KUnbalancedPTest, ::testing::Values(
    // Empty tree
    make_tuple(nullptr, 1, nullptr),
    
    // Single node tree
    []() {
        TreeNode* root = new TreeNode(1);
        return make_tuple(root, 1, nullptr);
    }(),
    
    // Example of a k-unbalanced tree (k=1)
    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    []() {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->right->right = new TreeNode(5);
        return make_tuple(root, 1, nullptr);  // Replace nullptr with actual expected k-unbalanced node
    }(),

    // Tree with height difference of 2 (k=1)
    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    //  /
    // 5
    []() {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->left->left = new TreeNode(5);
        return make_tuple(root, 1, root);  // Root should be k-unbalanced as left height=3, right height=1
    }()
));
