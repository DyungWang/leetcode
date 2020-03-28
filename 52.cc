#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> place(n, 0);
    return dfs(board, place, 0);
  }
 
 private:
  int dfs(vector<vector<int>>& board, vector<int>& place, int m) {
    if (m == board.size()) 
      return 1;
    int ret = 0;
    for (int i = 0; i < board[m].size(); ++i) {
      if (place[i] == 1) 
        continue;
      place[i] = 1;
      board[m][i] = 1;
      if (isValid(board, m, i))
        ret += dfs(board, place, m+1);
      board[m][i] = 0;
      place[i] = 0;
    }
    return ret;
  }

  bool isValid(const vector<vector<int>>& board, int m, int n) {
    for (int i = 1; m-i >= 0 && n-i >= 0; ++i) {
      if (board[m-i][n-i] == 1)
        return false;
    }
    for (int i = 1; m-i >= 0 && n+i < board[m].size(); ++i) {
      if (board[m-i][n+i] == 1)
        return false;
    }
    return true;
  }
};


int main(int, char**) {
  Solution solution;
  assert(solution.totalNQueens(4) == 2);
  return 0;  
}
