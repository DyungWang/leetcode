#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int movesToChessboard(vector<vector<int>>& board) {
    if (!canBeChessboard(board))
      return -1;
    return minSwapCountRow(board) + minSwapCountCol(board);
  }
 
 private:
  // 对于同一行/列中的格子来说，无论进行多少次行、列变换，这些格子始终处于同一行/列
  // 组成棋盘的条件：
  // 1. 任意两行/列的元素必须完全相同或完全不同
  //    对于  board[a][b], board[a][c], board[b][d], board[c][d]
  //    任意次数的行列变换不会改变他们的相对关系，要满则行 a, c 相同或相反，则必然有
  //    board[a][b] == board[a][d] and board[c][b] == board[c][d] 或 
  //    board[a][b] != board[a][d] and board[c][b] != board[c][d]    
  // 2. 在同一行/列中 0/1 的个数差必须小于等于 1, 如果大于1的话，则必然存在邻的两列/行元素相同，而不能组成棋盘
  bool canBeChessboard(const vector<vector<int>>& board) {
    int mLen = board.size();
    int nLen = board[0].size();
    for (int i = 0; i < mLen; ++i) for (int j = 0; j < nLen; ++j) {
      if ((board[0][0] ^ board[i][0]) ^ (board[0][j] ^ board[i][j])) 
        return false;
    }
    int mDiff = 0; for (const auto& row: board) mDiff += row[0] == 0 ? 1 : -1;
    int nDiff = 0; for (auto num: board[0]) nDiff += num == 0 ? 1 : -1;
    return abs(mDiff) <= 1 && abs(nDiff) <= 1;
  }

  // 因为交换两个奇数行或交换两个偶数行没有任何意义，因此只需要考虑交换奇偶行即可
  // c(1), c(0) 表示同一行中1，0的个数
  // o(1), o(0) 表示同一行中位于奇数列上的1, 0的个数 
  // 
  int minSwapCountRow(const vector<vector<int>>& board) {
    vector<int> all(2, 0);
    vector<int> odd(2, 0);
    for (int i = 0; i < board[0].size(); ++i) {
      all[0] += 1 - board[0][i];
      all[1] += board[0][i];
      if (i % 2 == 1) {
        odd[0] += 1 - board[0][i];
        odd[1] += board[0][i];
      }
    }
    if (all[1] == all[0]) 
      return min(all[0] - odd[0], all[1] - odd[1]);
    return all[1] > all[0] ? odd[1] : odd[0];
  }

  int minSwapCountCol(const vector<vector<int>>& board) {
    vector<int> all(2, 0);
    vector<int> odd(2, 0);
    for (int i = 0; i < board.size(); ++i) {
      all[0] += 1 - board[i][0];
      all[1] += board[i][0];
      if (i % 2 == 1) {
        odd[0] += 1 - board[i][0];
        odd[1] += board[i][0];
      }
    }
    if (all[1] == all[0]) 
      return min(all[0] - odd[0], all[1] - odd[1]);
    return all[1] > all[0] ? odd[1] : odd[0];
  }
};

vector<vector<int>> case1 = {
  { 0, 1, 1, 0 },
  { 0, 1, 1, 0 },
  { 1, 0, 0, 1 },
  { 1, 0, 0, 1 }
};

vector<vector<int>> case2 = {
  { 1, 0 },
  { 1, 0 }
};

vector<vector<int>> case3 = {
  { 1, 1, 0 },
  { 0, 0, 1 },
  { 0, 0, 1 }
};

int main(int, char**) {
  Solution solution;
  // assert(solution.movesToChessboard(case1) ==  2);
  // assert(solution.movesToChessboard(case2) == -1);
  solution.movesToChessboard(case3);
  return 0;
}
