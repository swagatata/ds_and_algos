#include<cstdio>
#include<ctime>
#include "big_exponent.h"

int main() {
    clock_t begin = clock();
    printf("%lld\n", bigExponent(2, 9999989, 9999991));    
    clock_t end = clock();
    printf("%u\n", (unsigned)(end - begin));

    return 0;
}
