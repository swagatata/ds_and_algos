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
#include<map>
#include<algorithm>

#include"graph.h"

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

#include "default_operators.hpp"
class edge : public default_operators<edge> {
public:
	int u, v;
	int weight;
		
	friend ostream& operator<<(ostream&, const edge&);

	edge(int weight = -1u, int u = -1, int v = -1){
        	init(weight, u, v);
	}
	
	void init(int weight, int u , int v){
    		this->weight = weight;
 	        this->u = u;
        	this->v = v;
	}

    // Used to implement all the comparators for edge.
	static int cmp(const edge &lhs, const edge &rhs)  {
	    int ret[] = {lhs.weight - rhs.weight, lhs.u - rhs.u, lhs.v-rhs.v};
	    FOR(i, 3) if(ret[i]) return ret[i];
	    return 0;
	}
};

template<class WEIGHT>
class AdjList<WEIGHT> : public Graph<WEIGHT>{
private:
	int V, E;
	int size;
	char * vnode;//can use enum to define vnodes and vedges
	char * vedge;
	map<int, edge> * list;
public:
	AdjList(int v){
		this->V = v;
		
	}
};
