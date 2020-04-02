#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int sum = 0; for (auto a : A) sum += a;
    int avg = sum / 3;
    if (avg * 3 != sum) return false;

    int sumL = 0, idxL = 0; 
    while (idxL < A.size() && (sumL += A[idxL]) != avg) 
      idxL++;

    int sumR = 0, idxR = A.size() - 1;
    while (idxR >= 0 && (sumR += A[idxR]) != avg) 
      idxR--;
    return idxL < idxR - 1;
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
  assert(solution.canThreePartsEqualSum(case1.A) == case1.res);
  assert(solution.canThreePartsEqualSum(case2.A) == case2.res);
  assert(solution.canThreePartsEqualSum(case3.A) == case3.res);
  assert(solution.canThreePartsEqualSum(case4.A) == case4.res);
  return 0;
}
