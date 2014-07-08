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
    int T, N;
    int ia, ib, ic;
    double da, db, dc;

    char * binary_str = new char[100000];

    input(&T);    
    FOR(i, T) {
    	input(&N);
    	fastStringInput(binary_str);
    	
    	//DEBUG cout << "fastStringInput successful" << endl ;

    	//calculate onePairCount    	
    	unsigned int oneCount = 0;
    	unsigned long long onePairCount = 0;

		size_t index = 0;
    	oneCount = (binary_str[index++] == '1');
    	onePairCount += oneCount;
    	
    	char c;
    	while((c = binary_str[index++]) != '\0') {
    		if (c == '1') {
    			++oneCount;
    			onePairCount += oneCount;
    		}
    	}

    	cout << onePairCount << endl ;
    }

    return 0;
}
