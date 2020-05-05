// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/05
// @link https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <string>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    return numsIslandsCopy(grid);
  }

 private:
  int numsIslandsCopy(vector<vector<char>> grid) {
    int cnt = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        cnt += grid[i][j] == '1';
        dfs(grid, i, j);
      }
    }
    return cnt;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size()) return;
    if (j < 0 || j >= grid[0].size()) return;
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
  }
};

struct TestCase {
  vector<vector<char>> grid;
  int lands;

  bool test() { return lands == Solution().numIslands(grid); }
};

TestCase testCase1 = {
  { 
    { '1', '1', '1', '1', '0' },
    { '1', '1', '0', '1', '0' },
    { '1', '1', '0', '0', '0' },
    { '0', '0', '0', '0', '0' }
  },
  1
};

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
#undef TEST
  return 0;
}
