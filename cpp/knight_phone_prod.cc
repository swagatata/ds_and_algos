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
// The solution is the set of all valid paths visiting all numeric nodes
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

using std::cout;
using std::vector;

typedef int Node;
typedef vector<vector<Node>> NodeGraph;

namespace {
const Node kStar = 10;
const Node kHash = 11;
}

// Thread unsafe.
class KnightOnPhone {
 public:
   void Solve(Node start, vector<vector<Node>>* output);
   
 private:
   void SolveInternal(Node current_node, int depth);
   
   static const NodeGraph graph_;
   vector<bool> visited_;
   vector<Node> result_;
   
   vector<vector<Node>>* output_;  // not owned.
};

// This represents the connectivity graph of the phone keypad 
// from the viewpoint of the knight (in adjacency list form).
// Indices 0 - 9 correspond to the digits. * is 10, # is 11.
const NodeGraph KnightOnPhone::graph_ = {
	{4, 6},         // 0
	{6, 8},         // 1
	{7, 9},         // 2
	{4, 8},         // 3
	{0, 3, 9},      // 4
	{kStar, kHash}, // 5
	{0, 1, 7},      // 6
	{2, 6, kHash},  // 7
	{1, 3},         // 8
	{2, 4, kStar},  // 9
	{5, 9},         // * (10)
	{5, 7},         // # (11)  
};

// This is a 12 stack frame deep graph search, so we can afford to 
// work with simple recursion. Node is a value type, so we use 
// pass by value and iteration with copy.
void KnightOnPhone::SolveInternal(Node current_node, int depth) {
	if (depth == graph_.size() - 1) {
    result_[depth] = current_node;
    output_->push_back(result_);  // copy.
		return;
	}
	for (const Node node : graph_[current_node]) {
	  if (!visited_[node]) {
      result_[depth + 1] = node;
      visited_[node] = true;
	    SolveInternal(node, depth + 1);
      visited_[node] = false;
      // result_[depth + 1] = -1;  // optional.
	  }
	}
}

void KnightOnPhone::Solve(Node start, vector<vector<Node>>* output) {
  // 5 is special in that a solution involving it will either not
  // include * or # (which is OK). So, instead of starting from 5,
  // we will always start from * (allowing 5 -> 7) or # 
  // (allowing 5 -> 9).
  if (start == 5) {
    Solve(kStar, output);
    Solve(kHash, output);
    return;
  }
  
  output_ = output;
  result_.clear();
  visited_.clear();
  result_.resize(graph_.size(), -1);
  visited_.resize(graph_.size(), false);
    
  result_[0] = start;
  visited_[start] = true;
  
  SolveInternal(start, 0);
}


int main() {
  KnightOnPhone solver;
  vector<vector<Node>> solutions;
  
  // Check out the other interesting values by
  // replacing the (1) below. 
  // 4, 6, 7, 8, 9 have no solutions.
  solver.Solve(1, &solutions);
  
  for (const auto& solution : solutions) {
    for (const Node node : solution) {
      if (node != kStar && node != kHash) {
        cout << node << ' ';    
      }
    }
		cout << '\n';
  }
  return 0;
}