#include "primes.h"
#include <iostream>

int main() {
  SieveOfEratosthenes sieve(100);
  std::cout << "Sieve : " << sieve << std::endl;
  std::cout << sieve.maxConsucutiveSum() << std::endl;

  return 0;
}