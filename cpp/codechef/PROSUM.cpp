#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<set>

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

inline void input(int *a) {
    register char c = 0;
    while (c < 33) c = getchar_unlocked();

    *a = 0;
    while(c > 33) {
        *a = (*a * 10) + c - '0'; 
        c = getchar_unlocked();
    }
}

int main(){
    int T, N;
    int ia, ib, ic;
    double da, db, dc;

    int * arr;
    int two_n, two_ng;
    long long pair_n;

    input(&T);
    FOR(i, T) {
        input(&N);
        arr = new int[N];
        FOR(j, N) {
            input(arr + j);    
        }
        two_n = two_ng = 0;
        pair_n = 0;
        FOR(j, N) {
            if (arr[j] == 2) { 
                pair_n += two_ng;
                two_n++;
            }
            if (arr[j] > 2) {
                pair_n += (two_n + two_ng);
                two_ng++;
            }
        }
        printf("%lld\n", pair_n);
        delete [] arr;
    }

    return 0;
}
