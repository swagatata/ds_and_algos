#include<cstdio>
#include<chrono>

using namespace std;

int main() {
    int a;
    //char * input_filename = "/Users/swagat/ds_and_algos/primes";
    
    int N = 664579;

    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0 ; i < N ; ++i)
        scanf("%d", &a);
    auto end = chrono::high_resolution_clock::now();

    auto duration = end - begin;
    printf("%lld\n", duration.count());
}
