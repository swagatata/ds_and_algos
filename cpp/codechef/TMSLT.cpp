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
#include<algorithm>

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

#define MOD 1000000
#define mult(a, b) (a * b)
#define square(a) mult(a, a)
#define nextS(S) (mult(a, square(S)) + mult(b, S) + c) % MOD

int main(){
    int T, N;
    long long ia, ib, ic;
    double da, db, dc;
    register int a, b, c, d;
    register int next_s;

    register bool* count;
    register int * next;
    long long * strength;
    bool isA = true;

    input(&T);
    FOR(i, T) {
        input(&N);
        input(&a);
        input(&b);
        input(&c);
        input(&d);

        next_s = d;

        if (N >= (MOD / 1000)) {
            if (a == 0) {
                if (b == 0) {
                    if (c == 0 || !(c % 2)) {
                        printf("%d\n", d);
                        continue;
                    }
                    else {
                        printf("%d\n", (d > c) ? (d - c) : (c - d));
                        continue;
                    }
                }
            }
            count = new bool[MOD];
            next = new int[MOD];
            //fill(next, next+MOD, 0);            
            memset(next, 0, sizeof(int) * MOD);

            for (long long j = 0 ; j < MOD ; ++j) {
                next[j] = nextS(j);
            }
    
            //fill(count, count+MOD, 0);            
            memset(count, 0, sizeof(bool) * MOD);
            count[next_s] = true;
            for (int j = 1; j < N; ++j) {
                next_s = next[next_s]; 
                count[next_s] = !count[next_s];
            }
    
            ia = ib = 0;
            isA = true;
            for (int j = MOD - 1 ; j >= 0 ; --j) {
                if (count[j]) {
                    if (isA) 
                        ia += j;
                    else
                        ib += j;
                    isA = !isA;
                }
            }
            printf("%lld\n", (ia > ib) ? (ia - ib) : (ib - ia));
            delete [] count;
            delete [] next;
        }
        else {
            strength = new long long[N];
            //fill(strength, strength+N, 0);
            memset(strength, 0, sizeof(long long) * N);

            strength[0] = d;
            for (int j = 1 ; j < N ; ++j) {
                strength[j] = nextS(strength[j-1]);
            }
            vector<int> v(strength, strength+N);
            make_heap(v.begin(), v.end());

            ia = ib = 0;
            isA = true;
            while(!v.empty()) {
                if (isA) 
                    ia += v.front();
                else 
                    ib += v.front();
                pop_heap(v.begin(), v.end()); 
                v.pop_back();
                isA = !isA;
            }
            printf("%lld\n", (ia > ib) ? (ia - ib) : (ib - ia));

            delete [] strength;
        }
    }
    
    return 0;
}
