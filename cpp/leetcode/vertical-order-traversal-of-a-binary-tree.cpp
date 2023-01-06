#include <fstream>
#include <iostream>
#include <assert.h>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORE(i, n) for (int i = n; i >= 0; i++)

#define p(t) cout << (t);
#define pn(t) cout << (t) << endl;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void dfs(TreeNode *node, int column, vector<vector<int>> &columns)
  {
    int index = 1000 + column;
    columns[index].push_back(node->val);
    if (node->left != nullptr)
    {
      dfs(node->left, column - 1, columns);
    }
    if (node->right != nullptr)
    {
      dfs(node->right, column + 1, columns);
    }
  }

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    if (root == nullptr)
    {
      return {};
    }
    vector<vector<int>> v(2000);
    pn(v.size());
    this->dfs(root, 0, v);
    vector<vector<int>> result;
    for (auto vec : v)
    {
      if (!vec.empty())
      {
        result.push_back(vec);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[])
{
  // p("one");
  auto *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  // p("two");
  Solution solution;
  auto v = solution.verticalTraversal(root);
  for (auto vec : v)
  {
    for (auto i : vec)
    {
      p(i);
      p(" ");
    }
    pn("");
  }
  pn("three");

  return 0;
}
