#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    if (grid.empty()) 
      return 0;
    init(grid);
    dfs(si, sj, 0);
    return total;
  }

 private:
  void init(vector<vector<int>>& grid) {
    this->grid = grid;
    mLen = grid.size();
    nLen = grid[0].size();
    total = 0;
    totalZero = 0;
    for (int i = 0; i < mLen; ++i) for (int j = 0; j < nLen; ++j) {
      if (grid[i][j] == 1) {
        si = i;
        sj = j;
      }
      totalZero += grid[i][j] == 0;
    }
  }

  void dfs(int ci, int cj, int step) {
    if (ci < 0 || ci >= mLen) return;
    if (cj < 0 || cj >= nLen) return;
    int cv = grid[ci][cj];
    if (cv == -1) return;
    if (cv ==  2) {
      total += step == (totalZero+1);
      return;
    }
    grid[ci][cj] = -1; // make it visit.
    dfs(ci+1, cj, step+1);
    dfs(ci, cj+1, step+1);
    dfs(ci-1, cj, step+1);
    dfs(ci, cj-1, step+1);
    grid[ci][cj] = cv; // back it
  }

 
 private:
  vector<vector<int>> grid;
  int mLen = 0;
  int nLen = 0;
  int si = 0;
  int sj = 0;
  int total = 0;
  int totalZero = 0;
};

vector<vector<int>> case1 = {
  { 1, 0, 0,  0 },
  { 0, 0, 0,  0 },
  { 0, 0, 2, -1 } 
};

vector<vector<int>> case2 = {
  { 1, 0, 0, 0 }, 
  { 0, 0, 0, 0 },
  { 0, 0, 0, 2 }
};

int main(int, char**) {
  Solution solution;
  assert(solution.uniquePathsIII(case1) == 2);
  assert(solution.uniquePathsIII(case2) == 4);
  return 0;
}
