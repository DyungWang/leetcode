#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int numEnclaves(vector<vector<int>>& A) {
    int mLen = A.size();
    int nLen = A[0].size();
    for (int i = 0; i < mLen; ++i) {
      dfs(A, i, 0);
      dfs(A, i, nLen-1);
    }
    for (int i = 0; i < nLen; ++i) {
      dfs(A, 0, i);
      dfs(A, mLen-1, i);
    }
    return countAndRecover(A);
  }
 
 private:
  void dfs(vector<vector<int>>& A, int i, int j) {
    int mLen = A.size();
    int nLen = A[0].size();
    if (i < 0 || i >= mLen) return;
    if (j < 0 || j >= nLen) return;
    if (A[i][j] != 1) return;
    A[i][j] = 2;
    dfs(A, i-1, j);
    dfs(A, i, j-1);
    dfs(A, i+1, j);
    dfs(A, i, j+1);
  }

  int countAndRecover(vector<vector<int>>& A) {
    int mLen = A.size();
    int nLen = A[0].size();
    int ret = 0;
    for (int i = 0; i < mLen; ++i) for (int j = 0; j < nLen; ++j) {
      if (A[i][j] == 1) 
        ++ret;
      if (A[i][j] == 2) 
        A[i][j] = 1;
    }
    return ret;
  }
};

vector<vector<int>> case1 = {
  { 0, 0, 0, 0 },
  { 1, 0, 1, 0 },
  { 0, 1, 1, 0 },
  { 0, 0, 0, 0 }
};

vector<vector<int>> case2 = {
  { 0, 1, 1, 0 },
  { 0, 0, 1, 0 },
  { 0, 0, 1, 0 },
  { 0, 0, 0, 0 }
};

int main(int, char**) {
  Solution solution;
  assert(solution.numEnclaves(case1) == 3);
  assert(solution.numEnclaves(case2) == 0);
  return 0;
}
