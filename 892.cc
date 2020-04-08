#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    if (grid.empty())
      return 0;
    int nLen = grid.size();
    int mLen = grid.back().size();
    int ret = 0;
    for (int i = 0; i < nLen; ++i) {
      for (int j = 0; j < mLen; ++j) {
        if (grid[i][j] == 0)
           continue;
        ret += grid[i][j] * 4 + 2;
        if (i-1 >= 0)   ret -= min(grid[i][j], grid[i-1][j]);
        if (i+1 < nLen) ret -= min(grid[i][j], grid[i+1][j]);
        if (j-1 >= 0)   ret -= min(grid[i][j], grid[i][j-1]);
        if (j+1 < mLen) ret -= min(grid[i][j], grid[i][j+1]);
      }
    }
    return ret;
  }
};

struct TestCase {
  vector<vector<int>> grid;
  int result;
};

#define TEST_F(testCase) \
  assert(Solution().surfaceArea(testCase.grid) == testCase.result);

TestCase testCase1 = {
  {
    { 2 }
  },
  10
};

TestCase testCase2 = {
  { 
    { 1, 2 },
    { 3, 4 } 
  },
  34
};

TestCase testCase3 = {
  {
    { 1, 0 },
    { 0, 2 }
  },
  16
};

TestCase testCase4 = {
  {
    { 2, 2, 2 },
    { 2, 1, 2 },
    { 2, 2, 2 }
  },
  46
};

int main(int, char**) {
  TEST_F(testCase1);
  TEST_F(testCase2);
  TEST_F(testCase3);
  TEST_F(testCase4);
  return 0;
}

