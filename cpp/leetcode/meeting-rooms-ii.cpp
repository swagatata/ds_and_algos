class Solution {
public:
  int computeMeetingRooms(vector<vector<int>>& meetings) {
    int n = meetings.size();
    vector<int> starts(n), ends(n);
    for (int i = 0; i < n; ++i) {
      starts[i] = meetings[i][0];
      ends[i] = meetings[i][1];
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int i = 0, j = 0, rooms = 0, maxRooms = 0;
    while (i < n) {
      if (starts[i] < ends[j]) {
        ++rooms;
        ++i;
      }
      else {
        --rooms;
        ++j;
      }
      maxRooms = max(maxRooms, rooms);
    }
    return maxRooms;
  }
};