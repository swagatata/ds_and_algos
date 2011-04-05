#include<queue>

/*
EW : edge_weight type
*/
template<class EW>
class Graph{
public:
	virtual int getN() = 0;
//Adds the necessary memory to the object to enable visiting of nodes.
	virtual void make_node_visitable() = 0;
	virtual void make_edge_visitable() = 0;	
	virtual bool is_edge(int u, int v) = 0;
	virtual void visit_edge() = 0;
	virtual void visit_node(int u) = 0;
	virtual bool is_visited(int u) = 0;
	virtual void mark_node_visited(int v) = 0;
	virtual void set_edge_weight(int , int, EW) = 0;
	virtual void dfs(int) = 0;	
	virtual void bfs(int) = 0;
	virtual ~Graph() {};
};

