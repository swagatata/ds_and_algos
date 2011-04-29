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
#define mset(a, b, c) {memset(a, b, c);}
#define readinput(input, size) {fread(input, 1, size, stdin)}

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

template <class T>
void parr(T arr[], int size, ostream& out = std::cout);

int main(){
    AdjMatrix mygraph(10);

	return 0;
}

template <class T>
void parr(T arr[], int size, ostream& out){
	for (int i = 0 ; i < size ; i++)
		out << arr[i] << " " ;
		
	out << endl ;	
}
