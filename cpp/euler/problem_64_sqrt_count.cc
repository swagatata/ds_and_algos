// Project Euler Problem 64
// Author: Divye Kapoor (divyekapoor@gmail.com)
//
// Find the number of odd repeating fraction coefficients for
// sqrt(N).
//
// eg. sqrt(N) = a0 + 1 / (a1 + 1 / (a2 + 1 / (a3 + ...)))
// For the coefficients a0, a1, a2, a3 ... it's guaranteed that
// they will repeat for irrational numbers. Find the numbers
// which have odd repetition loops.
//
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct RadicalFraction {
  int a;
  int b;
  int r;
  int c;
};

int gcd(int a, int b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);

  if (a == 0 && b == 0) return 1;
  if (a == 0) return b;
  return gcd(b%a, a);
}

RadicalFraction simplify(const RadicalFraction& rf) {
  int gcd_value = gcd(rf.a, rf.c);
  gcd_value = gcd(gcd_value, rf.b);

  RadicalFraction result = rf;
  result.a /= gcd_value;
  result.b /= gcd_value;
  result.c /= gcd_value;
  return result;
}

std::pair<int, RadicalFraction> evaluate(const RadicalFraction& rf) {
  int value = floor(abs((rf.a + rf.b * sqrt(rf.r)) / rf.c));
  RadicalFraction result = rf;
  result.a -= value * rf.c;
  return make_pair(value, result);
}

RadicalFraction invert(const RadicalFraction& rf) {
  RadicalFraction result;
  result.a = rf.a * rf.c;
  result.b = - rf.b * rf.c;
  result.r = rf.r;
  result.c = rf.a * rf.a - rf.b * rf.r;

  if (result.c < 0) {
    result.c = -result.c;
    result.a = -result.a;
    result.b = -result.b;
  }
  return simplify(result);
}

bool equal(const RadicalFraction& lhs, const RadicalFraction& rhs) {
  return lhs.a == rhs.a && lhs.b == rhs.b && lhs.r == rhs.r && lhs.c == rhs.c;
}

int main(int argc, char* argv[]) {
  if (argc != 2) return -1;

  int value;
  sscanf(argv[1], "%d", &value);

  int result_count = 0;

  for (int N = 2; N <= value; ++N) {
    int f = floor(sqrt(N));
    if (f*f == N) continue;

    RadicalFraction rf;
    rf.a = 0;
    rf.b = 1;
    rf.r = N;
    rf.c = 1;

    printf("%d: [", N);
    vector<pair<int, RadicalFraction>> seen;
    int repeat_count = 0;
    while (true) {
      auto result = evaluate(rf);

      int repeat_pos = 0;
      for (auto r : seen) {
        if (r.first == result.first && equal(r.second, result.second)) {
          repeat_count = seen.size() - repeat_pos;
          goto done;
        }
        ++repeat_pos;
      }
      seen.push_back(result);
      printf("%d,", result.first);
      rf = invert(result.second);
    }
done:
    printf("...] = %d\n", repeat_count);

    if (repeat_count % 2 == 1) {
      ++result_count;
    }
  }

  printf("\nNum odd periods = %d\n", result_count);
  return 0;
}
