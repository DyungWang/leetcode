#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    // sumL[a] = sum(A[a:a+L])
    // maxL[a] = max(sumL[a::])
    // sumM[a] = sum(A[a:a+M])
    // maxM[a] = max(sumM[a::]) 
    // tsum[a] = max(sumL[a]+maxM[a+L], sumM[a]+maxL[a+M])
    // res = max(tsum[::])
    auto sumL = initSumv(A, L);
    auto sumM = initSumv(A, M);
    auto maxL = initMaxv(sumL);
    auto maxM = initMaxv(sumM);
    int res = 0;
    for (int i = 0; i+L+M <= A.size(); ++i) {
      res = max(res, sumL[i]+maxM[i+L]);
      res = max(res, sumM[i]+maxL[i+M]);
    }
    return res;
  }
 
 private:
  vector<int> initSumv(const vector<int>& A, int l) {
    vector<int> sumv(A.size()+1, 0);
    for (int i = 0; i < l; ++i)
      sumv[0] += A[i];
    for (int i = 1; i <= A.size()-l; ++i)
      sumv[i] = sumv[i-1] - A[i-1] + A[i+l-1];
    return sumv;
  }

  vector<int> initMaxv(const vector<int>& S) {
    vector<int> maxv(S.size()+1, 0);
    for (int i = S.size()-1; i >= 0; --i) 
      maxv[i] = max(maxv[i+1], S[i]);
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
