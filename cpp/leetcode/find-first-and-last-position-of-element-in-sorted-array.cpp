#include "../everything.h"

class Solution {
public:

  vector<int> searchRange(vector<int>& nums, int target) {
    // use only one binary search
    // find the first occurrence of target
    // find the last occurrence of target
    // return the range
    int n = nums.size();
    int first = -1, last = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        first = m;
        r = m - 1;
      }
      else if (nums[m] < target) {
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    l = 0, r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        last = m;
        l = m + 1;
      }
      else if (nums[m] < target) {
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    return { first, last };
  }
  // vector<int> searchRange(vector<int>& nums, int target) {
  //   auto it = lower_bound(nums.begin(), nums.end(), target);
  //   if (it == nums.end() || *it != target) {
  //     return { -1, -1 };
  //   }
  //   auto it2 = upper_bound(nums.begin(), nums.end(), target);
  //   return { static_cast<int>(it - nums.begin()), static_cast<int>(it2 - nums.begin() - 1) };
  // }
};

int main() {
  Solution s;

  // initialise input
  // vector with 1 to 10 with some duplicates
  vector<int> nums = { 1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10 };


  // call function
  auto ans = s.searchRange(nums, 3);

  // assert output
  assert(ans.size() == 2);
  assert(ans[0] == 2);
  assert(ans[1] == 5);

  // check for non-existent element
  ans = s.searchRange(nums, 11);
  assert(ans.size() == 2);
  assert(ans[0] == -1);
  assert(ans[1] == -1);

  // check for first element
  ans = s.searchRange(nums, 1);
  assert(ans.size() == 2);
  assert(ans[0] == 0);
  assert(ans[1] == 0);

  // check for last element
  ans = s.searchRange(nums, 10);
  assert(ans.size() == 2);
  assert(ans[0] == 12);
  assert(ans[1] == 12);

  // check for element with only one occurrence
  ans = s.searchRange(nums, 9);
  assert(ans.size() == 2);
  assert(ans[0] == 11);
  assert(ans[1] == 11);

  // check with a vector with one element
  nums = { 1 };
  ans = s.searchRange(nums, 1);
  assert(ans.size() == 2);
  assert(ans[0] == 0);
  assert(ans[1] == 0);


  // check with an empty vector
  nums.clear();
  ans = s.searchRange(nums, 1);
  assert(ans.size() == 2);
  assert(ans[0] == -1);
  assert(ans[1] == -1);

}