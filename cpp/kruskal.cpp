#include<fstream>
#include<iostream>
#include<assert.h>
#include"kruskal.h"
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

void input(int &v, int &e, edge *& edges, istream& cin){
	cin >> v >> e ;	

	edges = new edge[e];
	for (int i = 0 ; i < e ; i++)
		{ cin >> edges[i].u >> edges[i].v >> edges[i].weight  ; }
}


int main(int argc, char * argv[]){
	ifstream fin(argv[1]);
	
	assert(fin != NULL);
	
	int V, E;
	edge * edges;

	input(V, E, edges, fin);	
	
	cout << kruskal(V, edges, edges + E) << endl ;
	return 0;
}
