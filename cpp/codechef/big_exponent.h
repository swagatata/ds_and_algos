#ifndef BIG_EXPONENT_SWAGAT
#define BIG_EXPONENT_SWAGAT

unsigned int nearestTwoPower(long long n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);
    return n ^ (n >> 1);
}

long long bigExponent(long long base, int exponent, long long modulo) {
    if (exponent == 0) 
        return 1;

    int e = exponent;
    long long result = 1;
    long long previousExponent = base;
    while (e) {
        if (e & 1) 
            result = (result * previousExponent) % modulo;
        previousExponent = (previousExponent * previousExponent) % modulo; 
        e >>= 1;
    }

    return result;
}
#endif
