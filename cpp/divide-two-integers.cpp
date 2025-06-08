#include <climits>  // For INT_MIN, INT_MAX
#include <cstdlib>  // For labs

// Add main function to make this compilable
int divide(int dividend, int divisor)
{
  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;
  int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
  long long dvd = labs(static_cast<long long>(dividend));
  long long dvs = labs(static_cast<long long>(divisor));
  int res = 0;
  while (dvd >= dvs)
  {
    long long temp = dvs, multiple = 1;
    while (dvd >= (temp << 1))
    {
      temp <<= 1;
      multiple <<= 1;
    }
    dvd -= temp;
    res += multiple;
  }
  return sign == 1 ? res : -res;
}

// Add main function to make this compilable as a standalone executable
#include <iostream>

int main() {
  std::cout << "10 / 3 = " << divide(10, 3) << std::endl;
  std::cout << "-10 / 3 = " << divide(-10, 3) << std::endl;
  std::cout << "10 / -3 = " << divide(10, -3) << std::endl;
  std::cout << "-10 / -3 = " << divide(-10, -3) << std::endl;
  std::cout << "INT_MIN / -1 = " << divide(INT_MIN, -1) << std::endl;
  
  return 0;
}