// given list of heights, find the max area of water that can be trapped

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  int left = 0;
  int right = n - 1;
  int maxArea = 0;
  while (left < right)
  {
    int area = min(heights[left], heights[right]) * (right - left);
    maxArea = max(maxArea, area);
    if (heights[left] < heights[right])
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  cout << maxArea << endl;
  return 0;
}