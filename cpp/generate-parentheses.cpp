// generate pairs of parenthesis given n
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void helper(vector<string> &res, string s, int left, int right)
{
  if (left == 0 && right == 0)
  {
    res.push_back(s);
    return;
  }
  if (left > 0)
  {
    helper(res, s + '(', left - 1, right);
  }
  if (right > left)
  {
    helper(res, s + ')', left, right - 1);
  }
}

vector<string> generateParenthesis(int n)
{
  vector<string> res;
  string s;
  helper(res, s, n, n);
  return res;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  // return empty vector if nums is empty
  if (nums.empty())
    return {};

  // sort the nums
  sort(nums.begin(), nums.end());

  // remove duplicates from nums
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  // create a vector to store the result
  vector<vector<int>> result;

  // loop through the nums
  for (int i = 0; i < nums.size(); i++)
  {
    // skip the duplicate nums
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    // loop through the rest of the nums
    for (int j = i + 1; j < nums.size(); j++)
    {
      // skip the duplicate nums
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      // set the left and right pointers
      int left = j + 1;
      int right = nums.size() - 1;

      // loop through the rest of the nums
      while (left < right)
      {
        // calculate the sum
        int sum = nums[i] + nums[j] + nums[left] + nums[right];

        // if the sum is less than the target, increment the left pointer
        if (sum < target)
          left++;

        // if the sum is greater than the target, decrement the right pointer
        else if (sum > target)
          right--;

        // if the sum is equal to the target, add the quadruplet to the result
        else
        {
          result.push_back({nums[i], nums[j], nums[left], nums[right]});
          left++;
          right--;
        }
      }
    }
  }

  // return the result
  return result;
}

int main()
{
  int n = 3;
  for (auto &s : generateParenthesis(n))
    cout << s << endl;
  return 0;
}