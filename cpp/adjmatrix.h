#include<algorithm>
#include<iostream>
#include<cstring>
#include "graph.h"
#include "default_operators.hpp"

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);
#define D(x) { std::cout << #x << ": " << x << endl; }

//max number of vertices Should be changed accordingly
#define MAXV 10000

using namespace std;

//try this template<class EW>
class AdjMatrix : public Graph<int>{
private:
	int V, E;
	int * matrix;
	int size;
	char * vnode;//can use enum to define vnodes and vedges
	char * vedge;
	
public:
	AdjMatrix(int v){
		this-> V = v;		
		this->vnode = this->vedge = NULL;
		this->size = v * (v + 1) / 2;
		this->matrix = new int[v * (v + 1) / 2];
		memset(matrix, 0, this->size * sizeof(int));
	}

	int getN(){return this->V;}

	virtual int get_edge_weight(int i, int j){
		if (j > i)
			swap(i, j);
		return matrix[twod_oned(i, j)];
	}
	
	void set_edge_weight(int u, int v, int weight){
		matrix[twod_oned(u, v)] = weight;
	}
private:
	int twod_oned(int i, int j){
		return (i+1) * i / 2 + j;
	}

	void oned_twod(int index, int &i, int &j){
		for(i = 0 ; i < MAXV ; i++)
			if ((i*i - i)/2 < index  && index < (i*i + i)/2)			
				break;			
		j = index - 1 - (i*i + i)/2;
	}

public:
	virtual void make_node_visitable(){
		if (!vnode){
			this->vnode = new char[this->V];
			memset(this->vnode, 0, this->V * sizeof(char));	
		}
		else
			for (int i = 0 ; i < this->V ; i++)
				this->vnode[i] = 0;
	}
	virtual void make_edge_visitable(){}
	virtual void visit_node(int v){
		cout << v << " " ;
	}
	virtual void mark_node_visited(int v){
		vnode[v] = 1;
	}
	virtual void visit_edge(){}
	bool is_edge(int i, int j){
		return (bool)get_edge_weight(i, j);			
	}
	bool is_visited(int v){
		return (bool)vnode[v];
	}
	void dfs(int v){
		make_node_visitable();
		recursive_dfs(v);
	}
	void recursive_dfs(int v){	
		visit_node(v);
		mark_node_visited(v);
		for (int i = 0 ; i < this->V ; i++){
			if (is_edge(v, i))
				if (!is_visited(i))					
					recursive_dfs(i);				
		}
	}
	void bfs(int v){
		make_node_visitable();
		queue<int> q;
		q.push(v);
		visit_node(v);
		mark_node_visited(v);
		while (!q.empty()){
			v = q.front();
			q.pop();
			for (int i = 0 ; i < this->V ; i++)
				if (is_edge(v, i))
					if (!is_visited(i)){
						mark_node_visited(i);
						visit_node(i);
						q.push(i);
					}					
		}
	}
};

