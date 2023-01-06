class Solution {
public:
  int nthUglyNumber(int n) {
    if (n == 1)
      return 1;

    vector<int> ugly_numbers;
    ugly_numbers.push_back(1);
    int ai = 0, bi = 0, ci = 0;
    int a, b, c;
    for (int i = 1; i < n; ++i) {
      a = ugly_numbers[ai] * 2;
      b = ugly_numbers[bi] * 3;
      c = ugly_numbers[ci] * 5;

      auto min = std::min(a, std::min(b, c));
      if (a == min)
        ai++;
      if (b == min)
        bi++;
      if (c == min)
        ci++;
      ugly_numbers.push_back(min);
    }
    return ugly_numbers.back();
  }
};