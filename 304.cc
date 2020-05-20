// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/20
// @link https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <vector>
#include <iostream>

using namespace std;

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) 
      return;
    mLen = matrix.size();
    nLen = matrix[0].size();
    sumv = vector<vector<int64_t>>(mLen+1, vector<int64_t>(nLen+1, 0));
    for (int i = mLen-1; i >= 0; --i)
      for (int j = nLen-1; j >= 0; --j) 
        sumv[i][j] = sumv[i+1][j] + sumv[i][j+1] - sumv[i+1][j+1] + matrix[i][j];
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    return sumv[row1][col1] - sumv[row1][col2+1] - sumv[row2+1][col1] + sumv[row2+1][col2+1];
  }
 
 private:
  int mLen = 0;
  int nLen = 0;
  vector<vector<int64_t>> sumv;
};

void test() {
  vector<vector<int>> matrix = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  };
  NumMatrix mat(matrix);
  cout << mat.sumRegion(2, 1, 4, 3) << endl;
  cout << mat.sumRegion(1, 1, 2, 2) << endl;
  cout << mat.sumRegion(1, 2, 2, 4) << endl;
}

int main(int, char**) {
  test();
  return 0;
}
