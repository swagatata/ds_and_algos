// given list of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // use binary search to find the first interval that overlaps with newInterval
    // then merge all the intervals that overlap with newInterval
    // then insert newInterval into the result

    // if newInterval is before all the intervals, insert it at the beginning
    // if newInterval is after all the intervals, insert it at the end
    

    vector<vector<int>> result;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i]);
      i++;
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    result.push_back(newInterval);
    while (i < intervals.size()) {
      result.push_back(intervals[i]);
      i++;
    }
    return result;
  }
};

int main() {
  vector<vector<int>> intervals = {{1,3},{6,9}};
  vector<int> newInterval = {2,5};
  Solution s;
  vector<vector<int>> result = s.insert(intervals, newInterval);
  for (auto v : result) {
    cout << v[0] << " " << v[1] << endl;
  }
  return 0;
}