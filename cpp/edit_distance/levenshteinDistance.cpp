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

#include "strings.h"

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

//Note : Doesn't work with negative numbers
inline void input(int *a) {
    register char c = 0;
    while (c < 33) c = getchar_unlocked();

    *a = 0;
    while(c > 33) {
        *a = (*a * 10) + c - '0'; 
        c = getchar_unlocked();
    }
}

//This function assumes that the string to be read ends with a new-line character.
//The user has to make sure the buffer size is enought to read the input string, or face the wrath of heap overflow.
inline void fastStringInput(char * str) {
    size_t index = 0;

    char c;
    c = getchar_unlocked();
    while(c != '\n') {
        str[index++] = c;
        c = getchar_unlocked();
    }

    str[index] = '\0';
}

int main(){
    int T;
    input(&T);

    char A[100];
    char B[100];

    FOR(i, T) {
        scanf("%s", A); 
        scanf("%s", B);
        
        cout << A << " " << B << " : " ;
        cout << wagnerFischer(A, B, strlen(A), strlen(B)) << endl ;
    }

    return 0;
}
