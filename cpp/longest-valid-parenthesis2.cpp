#include<iostream>

using namespace std;


class Solution {
public:
  int longestValidParentheses(string s) {
    // return length of longest valid parenthesis


  }
};

// main function to test above function
int main() {
  // create solution object and call longestValidParentheses
  Solution sol;
  cout << sol.longestValidParentheses("(()") << endl;
  cout << sol.longestValidParentheses(")()())") << endl;
  cout << sol.longestValidParentheses("()(()") << endl;
  cout << sol.longestValidParentheses("()(()()") << endl;
  cout << sol.longestValidParentheses("()(()()()") << endl;
  cout << sol.longestValidParentheses("()(()()()()") << endl;
  cout << sol.longestValidParentheses("()(()()()()()") << endl;
  cout << sol.longestValidParentheses("()(()()()()()()") << endl;
}