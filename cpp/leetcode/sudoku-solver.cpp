#include<iostream>
#include<vector>
#include<cstdlib>
#include<cassert>
#include<queue>

using namespace std;
class Solution {
  typedef shared_ptr<vector<bool>> vptr;
  struct Section {
    int section_i; // section number
    vptr filled;
    int n_filled;

    Section() {
      section_i = 0;
      filled = std::make_shared<vector<bool>>(9, false);
      n_filled = 0;
    }
    Section(int t): section_i(t) {
      filled = std::make_shared<vector<bool>>(9, false);
      n_filled = 0;
    }
    Section(int t, vptr f): section_i(t), filled(f), n_filled(0) {}
    // has function - mark the number as filled
    void has(int n) {
      if (filled->at(n))
        n_filled++;
      filled->at(n) = true;
    }

    // override operator <
    bool operator<(const Section& other) const {
      return n_filled < other.n_filled;
    }
  };
public:
  bool isValidEntry(vector<vector<char>>& board, size_t row, size_t col, char entry) {
    // validate empty
    if (board[row][col] != '.')
      return false;

    // validate row
    for (auto i = 0; i < 9; i++)
      if (board[row][i] == entry)
        return false;

    // validate col
    for (auto i = 0; i < 9; i++)
      if (board[i][col] == entry)
        return false;

    // validate box
    auto box_row = (row / 3) * 3;
    auto box_col = (col / 3) * 3;
    for (auto i = box_row; i < 3; ++i)
      for (auto j = box_col; j < 3; ++j)
        if (board[i][j] == entry)
          return false;

    return true;
  }

  priority_queue<Section> calculateFilled(vector<vector<char>>& board) {
    // calc rows
    unordered_map<int, Section> filled;
    priority_queue<Section> filledQ;
    for (auto i = 0; i < 9; ++i) {
      filled[i] = Section(0);
      filled[10 + i] = Section(10 + i);
      filled[20 + i] = Section(20 + i);
      for (auto j = 0; j < 9; ++j) {
        auto c = board[i][j];
        if (c != '.') {
          filled[i].has(c - '1');// push_back(board[i][j]);
          filled[10 + j].has(c - '1'); //->push_back(board[i][j]);
          auto box_no = (i / 3) * 3 + j / 3;
          filled[20 + box_no].has(c - '1'); //->push_back(board[i][j]);
        }
      }
    }
    for (auto& f : filled)
      filledQ.push(f.second);
    return filledQ;
  }

  bool tryToFill(vector<vector<char>>& board, Section& section) {
    // try to fill
    for (auto i = 0; i < 9; ++i) {
      if (section.filled->at(i))
        continue;
      // try to fill
      for (auto j = 0; j < 9; ++j) {
        if (isValidEntry(board, i, j, i + '1')) {
          board[i][j] = i + '1';
          section.has(i);
          return true;
        }
      }
    }
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    // track filled number 
    // rows: 0 to 8
    // cols: 10 to 18
    // boxes: 20 to 28
    auto filledQ = calculateFilled(board);
    while (!filledQ.empty()) {
      auto section = filledQ.top();
      if (section.n_filled == 9) {
        filledQ.pop();
        continue;
      }
      // try to fill       
      if (tryToFill(board, section)) {
        filledQ.pop();
        filledQ.push(section);
      }
    }
  }
};

int main() {

}