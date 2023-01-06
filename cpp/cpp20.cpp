// sample cpp 20 program
// 2021-08-01	PV

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;
// using namespace std::ranges;

int main()
{
  double foo = -0.0;
  double bar = 0.0;

  auto res = foo <=> bar;

  if (res < 0)
    std::cout << "-0 is less than 0";
  else if (res > 0)
    std::cout << "-0 is greater than 0";
  else if (res == 0)
    std::cout << "-0 and 0 are equal";
  else
    std::cout << "-0 and 0 are unordered";

  return 0;
}