/**
 * Remove duplicates from an array of char in a single pass. O(1) extra memory allowed.
 * Note: This solution uses extra memory of exactly 256 bits. Since 256 is a constant, the extra memory being used is O(1).
 * Side Note: The memory consumption of this solution is independent of the size of the input supplied to it as it doesn't
 * store the input values.
 * 
 * This code uses C++0x features. Compile with: g++ -std=c++0x <file>
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <bitset>

using namespace std;

int main() {
   bitset<1 << (sizeof(char)*8)> used;
   copy_if(istream_iterator<char>(cin), istream_iterator<char>(), ostream_iterator<char>(cout, " "), [&used](char v){ bool tmp = used[v]; used[v] = 1; return !tmp; });
   cout << endl;
   return 0;
}
