#include<cstdio>
#include<chrono>

using namespace std;

inline void fastRead(int *a) {
    register char c = 0;
    while (c < 33) c = getchar_unlocked();

    *a = 0;
    while(c > 33) {
        *a = (*a * 10) + c - '0'; 
        c = getchar_unlocked();
    }
}

int main() {
    int a;
    //char * input_filename = "/Users/swagat/ds_and_algos/primes";
    
    int N = 664579;

    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0 ; i < N ; ++i) {
        fastRead(&a);
        printf("%d", a);
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = end - begin;
    printf("%lld\n", duration.count());
}
