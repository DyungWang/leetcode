// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/15
// @link https://leetcode.com/problems/subrectangle-queries/

#include <vector>

using namespace std;

class SubrectangleQueries {
 public:
  SubrectangleQueries(vector<vector<int>>& rect): rect_(rect) {}
  
  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    for (int i = row1; i <= row2; ++i) 
      for (int j = col1; j <= col2; ++j)
        rect_[i][j] = newValue;
  }
  
  int getValue(int row, int col) {
    return rect_[row][col];
  }

 private:
  vector<vector<int>>& rect_;
};
