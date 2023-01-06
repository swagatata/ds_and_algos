// function to find the number of triplets that sum to zero
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &A)
{
  int n = A.size();
  if (n < 3)
    return {};
  vector<vector<int>> vv;
  sort(A.begin(), A.end());
  int count = 0;
  for (int i = 0; i < n - 2; i++)
  {
    if (i > 0 && A[i] == A[i - 1])
      continue;
    int j = i + 1, k = n - 1;
    while (j < k)
    {
      int sum = A[i] + A[j] + A[k];
      if (sum == 0)
      {
        vv.emplace_back(vector<int>{A[i], A[j], A[k]});
        while (j < k && A[j] == A[j + 1])
          j++;
        while (j < k && A[k] == A[k - 1])
          k--;
        j++;
        k--;
      }
      else if (sum < 0)
        j++;
      else
        k--;
    }
  }
  return vv;
}

int main()
{
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  for (auto &v : threeSum(v))
  {
    for (auto &i : v)
      cout << i << " ";
    cout << endl;
  }
  // cout << threeSum(v) << endl;
  return 0;
}

// Output

//     2

//     Time Complexity : O(n2)

//                           Space Complexity : O(1)

//                                                  My Personal Notes arrow_drop_up Save

//                                              Recommended Posts : Count triplets with sum smaller than a given value

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 2

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 3

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 4

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 5

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 6

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 7

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 8

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 9

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 10

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 11

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 12

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 13

//                                                                  Count triplets with sum smaller than a given value
//                                                                  |
//                                                                  Set 14

//                                                                  Count