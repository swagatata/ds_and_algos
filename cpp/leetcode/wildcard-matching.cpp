#include "../everything.h"

class Solution {
public:
  bool isMatch(string s, string p) {
    // match pattern p with string s
    // handle ? and * characters
    // ? matches any single character
    // * matches any sequence of characters (including the empty sequence)
    // the matching should cover the entire input string (not partial)

    // if p is empty, s must be empty
    if (p.empty()) return s.empty();

    // if p is not empty, s must be non-empty
    if (s.empty()) return false;

    // match * with empty string


    return 0;
  }
};

int main() {
  Solution s;

  // initialise input

  // call function
  auto ans = s.fn();

  // assert output
  assert(ans == 0);
}