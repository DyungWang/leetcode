#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    vector<int> sum(A.size(), A[0]);
    for (size_t i = 1; i < A.size(); ++i)
      sum[i] = sum[i-1] + A[i];
    for (int i = 0; i < A.size() - 2; ++i) {
      if (sum[i] * 3 != sum.back())
        continue;
      for (int j = i + 1; j < A.size() - 1; ++j) {
        if (sum[i] * 2 == sum[j])
          return true;
      }
    }
    return false;
  }
};

struct TestCase {
  vector<int> A;
  bool res;
};

TestCase case1 = { { 0,2,1,-6,6,-7,9,1,2,0,1 }, true };
TestCase case2 = { { 0,2,1,-6,6,7,9,-1,2,0,1 }, false };
TestCase case3 = { { 3,3,6,5,-2,2,5,1,-9,4 }, true };
TestCase case4 = { { 1,-1,1,-1 }, false };

int main(int, char**) {
  Solution solution;
  // assert(solution.canThreePartsEqualSum(case1.A) == case1.res);
  // assert(solution.canThreePartsEqualSum(case2.A) == case2.res);
  // assert(solution.canThreePartsEqualSum(case3.A) == case3.res);
  assert(solution.canThreePartsEqualSum(case4.A) == case4.res);
  return 0;
}
