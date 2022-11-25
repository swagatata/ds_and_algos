// create producer and consumer threads
#include <iostream>
#include <thread>
// create producer and consumer threads

int main() {
  // create thread
  std::thread t([]() {
    // print odd numbers from 1 to 100
    for (int i = 1; i <= 100; i += 2)
    std::cout << "odd : " << i << std::endl;
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