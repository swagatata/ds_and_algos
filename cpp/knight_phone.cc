// Author: divyekapoor@gmail.com
// Date: Jul 22, 2015
// 
// Problem: Given an old-style phone keypad with a knight on square 1.
// Find all 10 digit numbers that can be generated with the knight
// visiting each number exactly once.
//
// Answer:
// 1 8 3 4 0 6 7 2 9 5 
// 1 8 3 4 0 6 7 5 9 2 
// 
// Reason: Please see screenshot of the connectivity graph located at
//https://www.dropbox.com/s/16xl21v9hha85ad/IMG_20150722_015108542.jpg?dl=0 
// The solution is the set of all valid paths visiting all nodes
// starting from 1.
// This is implemented below via DFS.
//
// There is an analytical solution:
// Note the following:
// 1. edge (1, 6) can never be visited in a valid solution because 3 
//    and 8 are orphaned.
// 2. edge (4, 9) can never be visited in a valid solution because that
//    would orphan one of 0, 2, 5.
// 3. The cycle (7, 2, 9, *, 5, #) can be traversed either clockwise or
//    anticlockwise yielding the only 2 solutions.
//
#include <iostream>
#include <vector>

using namespace std;

typedef int Node;
typedef vector<vector<Node>> NodeGraph;

// This is a 12 stack frame deep graph search, so we can afford to 
// work with simple recursion. Node is a value type, so we use 
// pass by value and iteration with copy.
void DFS(Node current_node, int depth, const NodeGraph& graph, 
         vector<bool>* visited, vector<Node>* result) {
	if (depth == graph.size() - 1) {
    (*result)[depth] = current_node;
		for (const Node node : *result) {
      if (node != 10 && node != 11) {
        cout << node << ' ';    
      }
		}
		cout << '\n';
		return;
	}
	for (const Node node : graph[current_node]) {
	  if (!(*visited)[node]) {
      (*result)[depth + 1] = node;
      (*visited)[node] = true;
	    DFS(node, depth + 1, graph, visited, result);
      (*visited)[node] = false;
      // (*result)[depth + 1] = -1;  // optional.
	  }
	}
}


int main() {
	// This represents the connectivity graph of the phone keypad 
	// from the viewpoint of the knight (in adjacency list form).
	// Indices 0 - 9 correspond to the digits. * is 10, # is 11.
	NodeGraph graph = {
		{4, 6},      // 0
		{6, 8},      // 1
		{7, 9},      // 2
		{4, 8},      // 3
		{0, 3, 9},   // 4
		{10, 11},    // 5
		{0, 1, 7},   // 6
		{2, 6, 11},  // 7
		{1, 3},      // 8
		{2, 4, 10},  // 9
		{5, 9},      // * (10)
		{5, 7},      // # (11)
	};
	
	vector<Node> result(12, -1);
	vector<bool> visited(12, false);
	result[0] = 1;
  visited[1] = true;
	DFS(1, 0, graph, &visited, &result);
}