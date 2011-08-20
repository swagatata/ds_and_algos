#include <stdio.h>

template<int N>
struct X : X<N-1> {
    X() { printf("%d\n", N); }
};

template<>
struct X<0> {};

int main() {
    X<100> x;
    return 0;
}

