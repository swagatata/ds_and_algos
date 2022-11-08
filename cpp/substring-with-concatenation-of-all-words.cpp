class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    vector<int> res;
    if (words.empty())
      return res;
    int n = s.size(), cnt = words.size(), len = words[0].size();
    unordered_map<string, int> m;
    for (auto a : words)
      m[a]++;
    for (int i = 0; i < n - cnt * len + 1; i++)
    {
      unordered_map<string, int> seen;
      int j = 0;
      for (; j < cnt; j++)
      {
        string t = s.substr(i + j * len, len);
        if (m.find(t) != m.end())
        {
          seen[t]++;
          if (seen[t] > m[t])
            break;
        }
        else
          break;
      }
      if (j == cnt)
        res.push_back(i);
    }
    return res;
  }
};