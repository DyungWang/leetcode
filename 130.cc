// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/21
// @link https://leetcode.com/problems/surrounded-regions/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty())
      return;
    int mLen = board.size();
    int nLen = board[0].size();
    vector<vector<char>> result(mLen, vector<char>(nLen, 'X'));
    for (int i = 0; i < mLen; ++i) {
      dfs(board, result, i, 0, mLen, nLen);
      dfs(board, result, i, nLen-1, mLen, nLen);
    }
    for (int j = 1; j < nLen; ++j) {
      dfs(board, result, 0, j, mLen, nLen);
      dfs(board, result, mLen-1, j, mLen, nLen);
    }
    swap(board, result);
  }
 
 private:
  inline void dfs(vector<vector<char>>& board, vector<vector<char>>& result, 
      int i, int j, int mLen, int nLen) {
    if (i < 0 || i >= mLen) return;
    if (j < 0 || j >= nLen) return;
    if (board[i][j] == 'X') return;
    result[i][j] = 'O';
    board[i][j] = 'X';
    dfs(board, result, i-1, j, mLen, nLen);
    dfs(board, result, i+1, j, mLen, nLen);
    dfs(board, result, i, j-1, mLen, nLen);
    dfs(board, result, i, j+1, mLen, nLen);
  } 
};

struct TestCase {
  vector<vector<char>> input;
  vector<vector<char>> output;

  bool test() { 
    Solution().solve(input);
    return equal(input, output);
  }
};

TestCase testCase1 = {
  {
    { 'X', 'X', 'X', 'X' },
    { 'X', 'O', 'O', 'X' },
    { 'X', 'X', 'O', 'X' },
    { 'X', 'O', 'X', 'X' }
  },
  {
    { 'X', 'X', 'X', 'X' },
    { 'X', 'X', 'X', 'X' },
    { 'X', 'X', 'X', 'X' },
    { 'X', 'O', 'X', 'X' }
  }
};

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

