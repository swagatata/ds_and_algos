#include<algorithm>
#include<fstream>
#include<iostream>
#include<vector>
#include<climits>
#include<assert.h>

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);
#define D(x) { std::cout << #x << ": " << x << endl; }
using namespace std;

#define ll long long
#define ull unsigned long long

//#define DEBUG

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


ostream & operator<<(ostream &o, const edge &e) {
    o << "edge(weight = " << e.weight << ", source = " << e.u << ", dest = " << e.v << ")";
    return o;
}

class node {
public:	
	u_int vertex;
	node * parent;
	u_int rank;
	
	friend ostream& operator<<(ostream &, const node &);
	
	node(u_int vertex_ = -1u, node * parent_ = NULL, u_int rank_ = 0) : vertex(vertex_), parent(parent_), rank(rank_) 
	{
	    if(this->parent == NULL) {
	        this->parent = this;
	    }
	}

	node * find(){
		if (this != parent)
			parent = parent->find();
		return parent;
	}
	
	void union_(node &other){
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
	
protected:
    node(const node &n); // This class is non-copyable to avoid pointer issues.
};


ostream& operator<<(ostream &o, const node &n) {
    o << "node(vertex = " << n.vertex << ", parent = ";
    if(n.parent != &n) o << *n.parent;
    else o << &n;
    o << ", rank = " << n.rank << ")";
    
    return o;
}

// Use an iterator type so that it works with array pointers and vectors
// or any other vector like type
template<typename EdgeIterator>
u_int kruskal(int v, EdgeIterator edge_begin, EdgeIterator edge_end) {
    u_int e = std::distance(edge_begin, edge_end);
    
    // The comparator is given to create a min_heap instead of a max_heap
    // Removes an O(n) loop to multiply all edge weights by -1
    // Prevents modification of edges
	make_heap(edge_begin, edge_end, greater<__typeof(*edge_begin)>());
	
#ifdef DEBUG
    cout << endl;
	for (EdgeIterator it = edge_begin ; it != edge_end ; it++)
		cout << it->weight <<  " " << it->u << ' ' << it->v << endl ;
#endif	
	node * nodes = new node[v];
	for (int i = 0 ; i < v ; i++) {
		nodes[i].vertex = i;
	}
	
		
	int mstcost = 0;
	for (int i = 0 ; i < e ; i++){
		pop_heap(edge_begin, edge_end, std::greater<typeof(*edge_begin)>()); // use the comparator to make it a min_heap pop.
		--edge_end;
		u_int eu = edge_end->u;
		u_int ev = edge_end->v;
		if (nodes[eu].find() == nodes[ev].find()) {
			continue;
		}
		else{
			mstcost += edge_end->weight;			
			nodes[eu].union_(nodes[ev]);	
		}
	}
    
    delete[] nodes;
    
	return mstcost;
}

