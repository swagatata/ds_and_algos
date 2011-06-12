/**
 * Remove duplicates from an array of integers/char etc. without using additional memory 
 * 
 * This code uses C++0x features. Compile with: g++ -std=c++0x 
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
   vector<int> v;
   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
   sort(v.begin(), v.end());
   auto last = unique(v.begin(), v.end());
   copy(v.begin(), last, ostream_iterator<int>(cout, " "));
   cout << endl;
   return 0;
}
