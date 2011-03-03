#include<iostream>
#include"kruskal.h"

/* 1 vertex with self edge. mstcost should be 0. */
void one_vertex_test(){
	edge * edges = new edge(10, 0, 0);
	assert(kruskal(1, 1, edges) == 0);
	cout << "one_Vertex_test passed\n" ;
}

void two_vertex_two_edge_test(){
	edge * edges = new edge[2];
	edges[0].init(5, 0, 1);
	edges[1].init(10, 0, 1);
	assert(kruskal(2, 2, edges) == 5);
	cout << "two_vertex_two_edge_test passed\n" ;
}

void general_test(char * input_file){
	int v, e, mstcost;
	edge *edges;
	ifstream cin(input_file);
	cin >> v >> e ;	
	edges = new edge[e];

	for (int i = 0 ; i < e ; i++)
		{ cin >> edges[i].u >> edges[i].v >> edges[i].weight  ; }
	cin >> mstcost ;
	assert(kruskal(v, e, edges) == mstcost);
	cout << "general_tests passed\n" ;
}

int  main(int argc, char * argv[]){
	one_vertex_test();
	two_vertex_two_edge_test();
	
	if (argc > 1)
		for (int i = 1 ; i < argc ; i++)
			general_test(argv[i]);	
}
