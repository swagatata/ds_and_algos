#include <memory>
#include <iostream>
using namespace std;

class Pair
{
public:
  Pair(int x, int y) : x(x), y(y) {}
  // move constructor
  Pair(Pair &&p) : x(p.x), y(p.y) {}
  int x, y;

  // overload cout  << operator
  friend ostream &operator<<(ostream &os, const Pair &p)
  {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

int main()
{
  Pair p(1, 2);
  Pair p2(std::move(p));

  cout << p << endl;
  cout << p2 << endl;

  p.x = 3;
  cout << p << endl;
  cout << p2 << endl;
  return 0;
}