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

    int * W;
    int minVelocity;

    input(&T);
    for (int i = 0 ; i < T ; ++i) {
        input(&N);
        W = new int[N];
        for (int j = 0 ; j < N ; ++j)
            input(W + j);
        minVelocity = (W[N-1] - 1);
        for (int j = N - 1 ; j >= 0 ; --j) {
            minVelocity = (W[j] > ++minVelocity) ? W[j] : minVelocity;
        }
        printf("%d\n", minVelocity);
    }

    return 0;
}
