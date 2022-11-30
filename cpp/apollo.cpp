// include all common stl libraries
// include vector, string, stack, queue, set, map, unordered_map, unordered_set
// include iostream, fstream, sstream, cstdio, cstdlib, cstring, cctype, cassert

#include<vector>
#include<string>
#include<stack>
#include<queue>
// iostream
#include<iostream>



using namespace std;
/**
 * given a boolean 2d matrix of 0s and 1s, find the ones that move down together
 */
void findConnectedOnes(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 1) {
        dp[i][j] = 1;
        if (i > 0 && j > 0) {
          dp[i][j] += dp[i - 1][j - 1];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix = {
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 0, 1},
  };
  findConnectedOnes(matrix);
  return 0;
}