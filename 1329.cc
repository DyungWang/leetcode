#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if (mat.empty())
      return mat;
    for (int i = 0; i < mat.size(); ++i)
      diagonalSort(mat, i, 0);
    for (int j = 1; j < mat[0].size(); ++j)
      diagonalSort(mat, 0, j);
    return mat;
  }

 private:
  void diagonalSort(vector<vector<int>>& mat, int a, int b) {
    vector<int> nums;
    int i = a;
    int j = b;
    while (i < mat.size() && j < mat[0].size())
      nums.push_back(mat[i++][j++]);
    sort(nums.begin(), nums.end());
    while (i > a && j > b) {
      mat[--i][--j] = nums.back();
      nums.pop_back();
    }
  }
};

bool equal(const vector<int>& vec1, const vector<int>& vec2) {
  if (vec1.size() != vec2.size())
    return false;
  return equal(vec1.begin(), vec1.end(), vec2.begin());
}

bool equal(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
  if (mat1.size() != mat2.size())
    return false;
  for (int i = 0; i < mat1.size(); ++i)
    if (!equal(mat1[i], mat2[i]))
      return false;
  return true;
}

struct TestCase {
  vector<vector<int>> input;
  vector<vector<int>> output;
};

TestCase testCase1 = {
  {
    {3,3,1,1},
    {2,2,1,2},
    {1,1,1,2},
  },
  {
    {1,1,1,1},
    {1,2,2,2},
    {1,2,3,3},
  }
};

#define TEST(testCase) \
  assert(equal(testCase.output, Solution().diagonalSort(testCase.input)));

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

