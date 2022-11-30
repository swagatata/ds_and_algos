#include "general.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORE(i, n) for (int i = n; i >= 0; i++)

#define p(t) cout << (t);
#define pn(t) cout << (t) << endl;
#define in(n) scanf("%d", &n);
#define mset(a, b, c) \
  {                   \
    memset(a, b, c);  \
  }
#define readinput(input, size)   \
  {                              \
    fread(input, 1, size, stdin) \
  }

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

template <class T>
void parr(T arr[], int size, ostream& out = std::cout);


// struct with int and string with default constructor and equality operator
struct S {
  int i;
  string s;
  S(): i(0), s("") {}
  S(int i, string s): i(i), s(s) {}
  bool operator==(const S& other) const {
    return i == other.i && s == other.s;
  }
  // hash function for S
  friend struct std::hash<S>;
};

// hash function for S
namespace std {
  template <>
  struct hash<S> {
    size_t operator()(const S& s) const {
      return hash<int>()(s.i) ^ hash<string>()(s.s);
    }
  };
}


// compare two integers wrt number of 1 bits in their binary representation
bool compare(int a, int b) {
  int c1 = __builtin_popcount(a);
  int c2 = __builtin_popcount(b);
  if (c1 != c2)
    return c1 < c2;
  return a < b;
}

// sort a vector of integers with a compare function
void sort(vector<int>& v) {
  sort(v.begin(), v.end(), compare);
}

// sort an integer array with a compare function
void sort(int arr[], int size) {
  sort(arr, arr + size, compare);
}


// find max investment given a list of investments and asset ranges
int maxInvestment(vector<int>& investments, vector<vector<int>>& assetRanges) {
  int n = investments.size();
  int m = assetRanges.size();
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int l = assetRanges[i][0];
    int r = assetRanges[i][1];
    dp[l] = max(dp[l], investments[i]);
    dp[r + 1] = max(dp[r + 1], -investments[i]);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] += dp[i - 1];
  }
  return *max_element(dp.begin(), dp.end());
}

long maxValue(int n_assets, vector<vector<int>> investment_rounds) {
  vector<int> dp(n_assets + 1, 0);
  for (auto& round : investment_rounds) {
    int l = round[0];
    int r = round[1];
    int v = round[2];
    dp[l] = max(dp[l], v);
    dp[r + 1] = max(dp[r + 1], -v);
  }
  for (int i = 1; i <= n_assets; i++) {
    dp[i] += dp[i - 1];
  }
  return *max_element(dp.begin(), dp.end());
}

// sort a list of ranges by start value
void sortRanges(vector<vector<int>>& ranges) {
  sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
    });
}

// srand(time(NULL));
int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

int get_random_element(const unordered_set<int>& uset) {
  int index = random_int(0, uset.size() - 1);
  auto it = uset.begin();
  advance(it, index);
  return *it;
}

int main()
{
  // hashmap with key as pair<int, string> and value as int
  unordered_map<S, int> m;

  return 0;
}
