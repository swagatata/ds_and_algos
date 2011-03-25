#include<iostream>
#include<vector>
#include"kruskal.h"

/* 1 vertex with self edge. mstcost should be 0. */
void edge_comparison_test() {
    edge e1(10, 0, 1), e2(10, 0, 2), e3(10, 1, 1), e4(11, 0, 2);
    assert(e1 < e2);
    assert(e2 > e1);
    assert(e1 < e3);
    assert(e3 > e1);
    assert(e1 < e4);
    assert(e4 > e1);
    assert(e1 == e1);
    assert(e2 == e2);
    assert(e3 == e3);
    assert(e4 == e4);
    assert(e1 != e2);
    assert(e2 != e3);
    assert(e3 != e4);
}

void one_vertex_test(){
	std::vector<edge> edges;
	edges.push_back(edge(10, 0, 0));
	assert(kruskal(1, edges.begin(), edges.end()) == 0);
	cout << "one_Vertex_test passed\n" ;
}

void two_vertex_two_edge_test(){
	std::vector<edge> edges(2);
	edges[0].init(5, 0, 1);
	edges[1].init(10, 0, 1);
	assert(kruskal(2, edges.begin(), edges.end()) == 5);
	cout << "two_vertex_two_edge_test passed\n" ;
}

void two_vertex_two_edge_test_decreasing_order(){
	std::vector<edge> edges(2);
	edges[0].init(10, 0, 1);
	edges[1].init(5, 0, 1);
	assert(kruskal(2, edges.begin(), edges.end()) == 5);
	cout << "two_vertex_two_edge_test_decreasing_order passed\n" ;
}

void two_vertex_two_edge_repeat_calls(){
	std::vector<edge> edges(2);
	edges[0].init(10, 0, 1);
	edges[1].init(5, 0, 1);
	assert(kruskal(2, edges.begin(), edges.end()) == 5);
	cout << "two_vertex_two_edge_repeat_calls passed\n" ;
}



void general_test(char * input_file){
	u_int v, e, mstcost;
	
	ifstream cin(input_file);
	cin >> v >> e ;	
	std::vector<edge> edges(e); 

	for (int i = 0 ; i < e ; i++)
		{ cin >> edges[i].u >> edges[i].v >> edges[i].weight  ; }
	cin >> mstcost ;
	assert(kruskal(v, edges.begin(), edges.end()) == mstcost);
	cout << "general_tests passed\n" ;
}

int  main(int argc, char * argv[]){
    edge_comparison_test();
	one_vertex_test();
	two_vertex_two_edge_test();
	two_vertex_two_edge_test_decreasing_order();
	
	
	if (argc > 1)
		for (int i = 1 ; i < argc ; i++)
			general_test(argv[i]);	
}
