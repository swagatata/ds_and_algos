#include<algorithm>
#include<fstream>
#include<iostream>
#include<assert.h>

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);

using namespace std;

#define ll long long
#define ull unsigned long long

//#define DEBUG

class edge{
public:
	int u, v;
	int weight;
		
	edge(){}
	
	bool operator<(const edge &other){
		return ((this->weight < other.weight) || (this->weight == other.weight && this->u < other.u) || (this->weight == other.weight && this->u == other.u && this->v < other.v));
	}
	
	bool operator==(const edge &other){
		return (this->weight == other.weight && this->u == other.u && this->v == other.v);
	}
};

void input(int &v, int &e, edge *& edges, istream& cin){
	cin >> v >> e ;	

	edges = new edge[e];
	for (int i = 0 ; i < e ; i++)
		{ cin >> edges[i].u >> edges[i].v >> edges[i].weight  ; }
}

class node{
public:	
	u_int vertex;
	node * parent;
	u_int rank;
	
	node(){parent = this; rank = 0;}
	
	node * find(){
		if (this != parent)
			parent = parent->find();
		return parent;
	}
	
	void nion(node &other){
		if (find() == other.find())
			return;
		else{
			if (rank < other.rank)
				parent->parent = other.parent;
			else{
				other.parent->parent = parent;
				if (rank == other.rank)
					rank++;
			}				
		}
	}
};

u_int kruskal(int v, int e, edge *& edges){
	for (int i = 0 ; i < e ; i++)
		edges[i].weight *= -1;

	make_heap(edges, edges+e);
#ifdef DEBUG
	for (int i = 0 ; i < e ; i++)
		cout << edges[i].weight <<  " " << edges[i].u << ' ' << edges[i].v << endl ;
	cout << endl ;	
#endif	
	node * nodes = new node[v];	
	for (int i = 0 ; i < v ; i++)
		nodes[i].vertex = i;
		
	u_int mstcost = 0;
	for (int i = 0 ; i < e ; i++){
		pop_heap(edges, edges+e-i);
		u_int eu = edges[e-i-1].u;
		u_int ev = edges[e-i-1].v;
		if (nodes[eu].find() == nodes[ev].find())
			continue;
		else{
			mstcost += (-1 * edges[e-i-1].weight);
			nodes[eu].nion(nodes[ev]);	
		}
	}
	
	return mstcost;
}

int main(int argc, char * argv[]){
	ifstream fin(argv[1]);
	
	assert(fin != NULL);
	
	int V, E;
	edge * edges;

	input(V, E, edges, fin);	
	
	cout << kruskal(V, E, edges) << endl ;
	return 0;
}
