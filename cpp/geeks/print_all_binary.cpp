#include "print_all_binary.h"
// print all binary numbers of size n
#include <iostream>
#include <boost/dynamic_bitset.hpp>

void print_all_binary_recursion(boost::dynamic_bitset<> &bits, size_t index) {
    if (index == bits.size()) {
        std::cout << bits << "\n";
        return;
    }
    bits[index] = 0;
    print_all_binary_recursion(bits, index+1);
    bits[index] = 1;
    print_all_binary_recursion(bits, index+1);
}

void print_all_binary(size_t n) {
    if (n == 0)
        return;
    
    boost::dynamic_bitset<> bits(n);
    print_all_binary_recursion(bits, 0);
}

int main() {
    print_all_binary(10);
}