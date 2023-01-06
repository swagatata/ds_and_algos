#include "general.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <thread>

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORE(i, n) for (int i = n; i >= 0; i++)

#define p(t) cout << (t);
#define pn(t) cout << (t) << endl;
#define in(n) scanf("%d", &n);
#define mset(a, b, c) \
  {                   \
    memset(a, b, c);  \
  }
#define readinput(input, size)   \
  {                              \
    fread(input, 1, size, stdin) \
  }

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

template <class T>
void parr(T arr[], int size, ostream& out = std::cout);

int main()
{
  mutex m;
  // lock_guard<mutex> lock(m);
  // create thread
  std::thread t([]() {
    // print odd numbers from 1 to 100
    for (int i = 1; i <= 100; i += 2) {
      // lock on mutex      
      std::cout << "odd : " << i << std::endl;
    }
  // std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    });

  // create thread
  std::thread t2([]() {
    // print even numbers from 1 to 100
    for (int i = 2; i <= 100; i += 2)
    std::cout << "even : " << i << std::endl;
  // std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    });
  t.join();
  t2.join();

  return 0;
}
