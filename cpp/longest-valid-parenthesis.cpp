class Solution {
public:
  int longestValidParentheses(string s) {
    auto size = s.size();
    if (size <= 1)
      return 0;


    auto ispalin = vector<vector<bool>>(size);
    for (auto it = ispalin.begin(); it != ispalin.end(); ++it)
      *it = vector<bool>(size);

    int psize = 2;
    int maxpsize = 0;
    vector<int> maxpsize_at(size);
    for (int i = 0; i + psize <= size; ++i) {
      ispalin[i][0] = true;
      if (s[i] == '(' && s[i + 1] == ')') {
        ispalin[i][psize] = true;
        maxpsize = 2;
        maxpsize_at[i] = psize;
      }
    }

    for (psize = 4; psize <= size; psize += 2) {
      for (int i = 0; i + psize <= size; ++i) {
        if (
          (s[i] == '(' && s[i + psize - 1] == ')' && ispalin[i + 1][psize - 2]) ||
          (s[i] == '(' && s[i + 1] == ')' && ispalin[i + 2][psize - 2]) ||
          (s[i + psize - 2] == '(' && s[i + psize - 1] == ')' && ispalin[i][psize - 2]) ||
          (maxpsize_at[i] && ispalin[i + maxpsize_at[i]][psize - maxpsize_at[i]])
          ) {
          ispalin[i][psize] = true;
          maxpsize = psize;
          maxpsize_at[i] = psize;
        }
      }
    }

    return maxpsize;
  }
};