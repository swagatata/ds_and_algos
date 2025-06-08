#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include <optional>

using namespace std;

// Binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Equality operator for TreeNode
inline bool operator==(const TreeNode& a, const TreeNode& b) {
    if (a.val != b.val) return false;
    if ((a.left == nullptr) != (b.left == nullptr)) return false;
    if ((a.right == nullptr) != (b.right == nullptr)) return false;
    bool left_eq = (!a.left && !b.left) || (a.left && b.left && *a.left == *b.left);
    bool right_eq = (!a.right && !b.right) || (a.right && b.right && *a.right == *b.right);
    return left_eq && right_eq;
}

// Custom printer for Google Test
void PrintTo(const optional<TreeNode>& node, ::std::ostream* os) {
    if (!node) {
        *os << "nullopt";
    } else {
        *os << "TreeNode(" << node->val << ")";
    }
}

// Helper function to delete a tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Function to find k-unbalanced node in a binary tree
// Returns nullopt if no k-unbalanced node is found
// A node is k-unbalanced if the difference in heights of its left and right subtrees is greater than k
optional<TreeNode> findKUnbalanced(const TreeNode& root, int k) {
    // TODO: Implement the function
    return nullopt;
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
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    
    EXPECT_EQ(findKUnbalanced(root, 1), nullopt);
}

// Parameterized test
class KUnbalancedPTest : public ::testing::TestWithParam<tuple<optional<TreeNode>, int, optional<TreeNode>>> {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

TEST_P(KUnbalancedPTest, DifferentCases) {
    auto [root, k, expected] = GetParam();
    
    if (!root) {
        EXPECT_THROW(findKUnbalanced(*root, k), std::invalid_argument);
    } else {
        EXPECT_EQ(findKUnbalanced(*root, k), expected);
    }
}

// Example test cases
INSTANTIATE_TEST_SUITE_P(KUnbalancedPTest, KUnbalancedPTest, ::testing::Values(
    // Empty tree
    make_tuple(nullopt, 1, nullopt),
    
    // Single node tree
    []() {
        TreeNode root(1);
        return make_tuple(optional<TreeNode>(root), 1, nullopt);
    }(),
    
    // Example of a k-unbalanced tree (k=1)
    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    []() {
        TreeNode root(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left->left = new TreeNode(4);
        root.right->right = new TreeNode(5);
        return make_tuple(optional<TreeNode>(root), 1, nullopt);  // Replace nullopt with actual expected k-unbalanced node
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
        TreeNode root(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left->left = new TreeNode(4);
        root.left->left->left = new TreeNode(5);
        return make_tuple(optional<TreeNode>(root), 1, optional<TreeNode>(root));  // Root should be k-unbalanced as left height=3, right height=1
    }()
));
