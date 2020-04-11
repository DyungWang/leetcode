// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11
// @link https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    dfs(result, board, 0);
    return result;
  }

 private:
  void dfs(vector<vector<string>>& result, vector<string>& board, int i) {
    if (i == board.size()) {
      result.push_back(board);
      return;
    }
    for (int j = 0; j < board.size(); ++j) {
      board[i][j] = 'Q';
      if (valid(board, i, j))
        dfs(result, board, i+1);
      board[i][j] = '.';
    }
  }

  bool valid(vector<string>& board, int i, int j) {
    // check column
    for (int a = 0; a < i; ++a) 
      if (board[a][j] == 'Q') return false;
    // check left upper
    for (int a=i-1, b=j-1; a>=0 && b>=0; --a, --b)
      if (board[a][b] == 'Q') return false;
    // check right upper
    for (int a=i-1, b=j+1; a>=0 && b<board.size(); --a, ++b)
      if (board[a][b] == 'Q') return false;
    return true;
  }
};

struct TestCase {
  int n;
  vector<vector<string>> result;
};

TestCase testCase1 = {
  4,
  {
    {
      ".Q..", 
      "...Q",
      "Q...",
      "..Q." 
    },
    {
      "..Q.",
      "Q...",
      "...Q",
      ".Q.."
    }
  }
};

void TEST(TestCase testCase) {
  bool ret = equal(testCase.result, Solution().solveNQueens(testCase.n));
  assert(ret);
}

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
