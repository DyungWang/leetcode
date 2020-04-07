#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    // sumv[a][b]: sum(A[a:b])
    // maxv[a+b][c]: max(sumv(j:j+c)) where j>=a+b
    // dp[a][b][c]: sumv[a:b] + maxv[a+b][c]
    auto sumv = initSumv(A);
    auto maxv = initMaxv(sumv);
    int res = 0;
    for (int a = A.size()-1; a >= 0; --a) {
      if (a+L+M <= A.size()) {
        res = max(res, sumv[a][a+L-1] + maxv[a+L][M]);
        res = max(res, sumv[a][a+M-1] + maxv[a+M][L]);
      }
    }
    return res;
  }
 
 private:
  vector<vector<int>> initSumv(const vector<int>& A) {
    vector<vector<int>> sumv(A.size()+1, vector<int>(A.size()+1, 0));
    for (int i = A.size()-1; i >= 0; --i) {
      for (int j = A.size()-1; j >= i; --j) {
        sumv[i][j] = sumv[i+1][j] + A[i];
      }
    }
    return sumv;
  }

  vector<vector<int>> initMaxv(const vector<vector<int>>& sumv) {
    vector<vector<int>> maxv(sumv.size()+1, vector<int>(sumv.size()+1, 0));
    for (int i = sumv.size()-1; i >= 0; --i) {
      for (int j = 1; i+j < sumv.size(); ++j) {
        maxv[i][j] = max(maxv[i+1][j], sumv[i][i+j-1]); 
      }
    }
    return maxv;
  }
};

struct TestCase {
  vector<int> A;
  int L;
  int M;
  int R;
};
#define TEST_F(testCase) \
  assert(Solution().maxSumTwoNoOverlap(testCase.A, testCase.L, testCase.M) == testCase.R);

TestCase testCase1 = { {0,6,5,2,2,5,1,9,4}, 1, 2, 20 };
TestCase testCase2 = { {3,8,1,3,2,1,8,9,0}, 3, 2, 29 };
TestCase testCase3 = { {2,1,5,6,0,9,5,0,3,8}, 4, 3, 31 };
TestCase testCase4 = { {1,0,3}, 1, 2, 4 };

int main(int, char**) {
  TEST_F(testCase1);
  TEST_F(testCase2);
  TEST_F(testCase3);
  TEST_F(testCase4);
  return 0;
}
