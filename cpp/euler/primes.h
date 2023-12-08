#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

#define ll long long
#define ull unsigned long long

/**
 * Helpful Links :
 * 1. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * 2. https://www.cplusplus.com/reference/sstream/ostringstream/
 */
class SieveOfEratosthenes {
private:
  std::vector<bool> sieve;
  std::vector<int> primes;

  void initializeSieve() {
    sieve[0] = sieve[1] = false;
    for (unsigned candidate = 2; candidate < sieve.size(); candidate++) {
      if (sieve[candidate]) {
        primes.push_back(candidate);
        unsigned consonant = candidate + candidate;
        while(consonant < sieve.size()) {
          sieve[consonant] = false;
          consonant += candidate;
        }
      }
    }
  }
public:
  SieveOfEratosthenes(size_t max) : sieve(max+1, true), primes(1024) {
    this->initializeSieve();
  }
  friend std::ostream& operator<<(std::ostream& os, SieveOfEratosthenes const& sieve);

  /**
   * Problem : https://projecteuler.net/problem=50
   */
  unsigned maxConsucutiveSum() {
    unsigned max_prime = sieve.size() - 1;
    unsigned n_primes = primes.size();

    // Tha maximum continuous sequence could be n - 1 where n is the total number of primes in given range
    for (unsigned size = n_primes - 1; size > 1; --size) {
      // loop over starting point
      ull consecutive_sum = 0;
      // start_i is supposed to be the index of the last element in the
      // consecutive array of primes we are considering
      unsigned start_i = 0;
      for (unsigned i = 0; i < size; ++i) {
        consecutive_sum += primes[n_primes - 1 - i];
      }
      do {
        if (consecutive_sum <= max_prime) {
          if (sieve[consecutive_sum]) {
            return consecutive_sum;
          }
        }
        start_i++;
        // std::cout << max_prime << " " << n_primes << " " << size <<  " " << start_i << std::endl;
        if (n_primes >= (start_i + size)) {
          consecutive_sum -= primes[n_primes - start_i];
          consecutive_sum += primes[n_primes - (start_i + size)];
        } else {
          break;
        }
      } while(true);
    }
    return *(primes.end() - 1);
  }
};

std::ostream& operator<<(std::ostream& os, SieveOfEratosthenes const& sieve) {
  std::ostringstream ss;
  for (unsigned i = 0; i < sieve.sieve.size(); ++i) {
    if (sieve.sieve[i]) {
      ss << i << " ";
    }
  }
  return os << ss.str();
}