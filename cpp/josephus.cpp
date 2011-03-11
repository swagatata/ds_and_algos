#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

using namespace std;

int josephus(int t, int n){
	if (t == 1)
		return 1;
		
	int temp = ((n == t)? n : n%t) + josephus(t - 1, n);
	return (temp == t) ? temp : (temp%t);
}

int main(){
    int T, n;
    cout << "Enter T followed by N : " ;
    

    cin >> T >> n;
    cout << josephus(T, n) << endl ;		
}
