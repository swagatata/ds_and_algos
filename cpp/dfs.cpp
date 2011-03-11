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
#include"adjmatrix.h"
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

int main(){
	int ia, ib, ic;
	double da, db, dc;

	int T, V, E;
	cout << "Program for Depth-First-Search\n" ;
	cout << "Enter No of Vertices : " ; cin >> V ;
	Graph<int> * g = new AdjMatrix(V);
	
	cout << "Enter No of Edges : " ; cin >> E ;
	int u, v, weight;
	FOR(i, E){
		cout << "Enter edge " << i + 1 << " (format : u v weight): " ;
		cin >> u >> v >> weight;
		g->set_edge_weight(u, v, weight);
	}

	g->dfs(0);
	cout << endl ;
	g->bfs(0);
	

	return 0;
}
