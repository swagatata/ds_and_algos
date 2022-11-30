// include all stl libraries
#include "everything.h"

void use_lower_bound() {
  std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  auto it = std::lower_bound(v.begin(), v.end(), 5);
  // should display 4
  std::cout << it - v.begin() << std::endl;

  v[3] = 5;
  it = std::lower_bound(v.begin(), v.end(), 5);
  // should display 3 - finds first occurrence
  std::cout << it - v.begin() << std::endl;
}

void use_upper_bound() {
  std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  // find first element greater than 5
  auto it = std::upper_bound(v.begin(), v.end(), 5);
  // should print 5
  std::cout << it - v.begin() << std::endl;

  v[3] = 5;
  it = std::upper_bound(v.begin(), v.end(), 5);
  // should print 5
  std::cout << it - v.begin() << std::endl;
}

int main() {
  use_lower_bound();
  use_upper_bound();
}