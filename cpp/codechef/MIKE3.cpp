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

inline void input(int &a) {
    register char c = 0;
    while (c < 33) c = getchar_unlocked();

    a = 0;
    while(c > 33) {
        a = (a * 10) + c - '0'; 
        c = getchar_unlocked();
    }
}

int main(){
    int M, N;
    int ia, ib, ic;
    double da, db, dc;

    input(N);
    input(M);

    int * offerSizes = new int[M];
    int ** offers = new int*[M];
    FOR(i, M) {
        input(offerSizes[i]);
        offers[i] = new int[offerSizes[i]];
        FOR(j, offerSizes[i]) {
            input(offers[i][j]);
            //pn(offers[i][j])
        }
    }

    if (M == 1) { 
        printf("1");
        return 0;
    }

    //get all possible groups of offers of size 2
    int ** groupsOfTwo = new int*[(M * (M - 1)) / 2];

    return 0;
}
