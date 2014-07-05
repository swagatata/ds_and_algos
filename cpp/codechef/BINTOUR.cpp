#include<cstdio>

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

unsigned primeModInverse(unsigned a, unsigned mod) {
    return bigExponent(a, mod - 2, mod);
}

#define MOD 1000000009
#define mul(a, b) ((((unsigned long long)a) * (b)) % MOD)
#define pu(u) printf("%u\n", u);
#define pdu(s, u) printf(s); printf("%u\n", u);

int main() {
    unsigned kminus1Factorials[19] = {1, 2, 24, 40320, 789699702, 461835440, 912856827, 147463093, 728198416, 968572994, 814032850, 915461857, 985030198, 302598817, 377694719, 467172479, 232578394, 448894489, 244927178}; 
    unsigned twoPowers[19] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
    unsigned preFactorial[19] = {1, 1, 6, 5040, 674356237, 514432362, 467388392, 399589559, 440344529, 654235500, 561341834, 488239976, 873775650, 942297689, 159752058, 341597512, 558444716, 157100289, 110375386};

    unsigned K;
    scanf("%u", &K);

    unsigned constant = mul(kminus1Factorials[K-1], twoPowers[K-1]); 
    //pdu("constant : ", constant)
    for (int i = 1 ; i < (twoPowers[K-1]/2) ; ++i) 
        printf("0\n");
    
    unsigned nConfigurations = mul(constant, preFactorial[K-1]);
    printf("%u\n", nConfigurations);

    unsigned count = 1;
    for (int i = (twoPowers[K-1]/2 + 1) ; i <= twoPowers[K-1] ; ++i) {
        nConfigurations = mul(nConfigurations, i - 1); 

        nConfigurations = mul(nConfigurations, primeModInverse(count, MOD));
        count++;
        printf("%u\n", nConfigurations);
    }

    //unsigned twoModInverse = primeModInverse(2, 1000000009); 
    //printf("%u\n", (2 * twoModInverse) % 1000000009);
}
