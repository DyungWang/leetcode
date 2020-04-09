// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/09
// @link https://leetcode.com/problems/three-equal-parts
// @discuss https://leetcode.com/problems/three-equal-parts/discuss/183922/C%2B%2B-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& A) {
    int cnt = countOne(A);
    if (cnt == 0) 
      return {0, (int)A.size()-1};
    if (cnt % 3 != 0)
      return {-1, -1};
    int s = countOne(A, 0,   1);
    int m = countOne(A, s+1, cnt/3);
    int e = countOne(A, m+1, cnt/3);
    while (e < A.size() && A[s] == A[m] && A[m] == A[e]) {
      s++; m++; e++;
    }
    return e == A.size() ? vector<int>({s-1, m}) : vector<int>({-1, -1});
  }

 private:
  int countOne(const vector<int>& A) {
    int cnt = 0;
    for (auto a : A) cnt += a;
    return cnt;
  }

  int countOne(const vector<int>& A, int s, int c) {
    for (int i = s; i < A.size(); ++i) {
      if ((c -= A[i]) == 0) 
        return i;
    }
    return A.size();
  }
};

struct TestCase {
  vector<int> A;
  vector<int> R;
};

bool equal(const vector<int>& R1, const vector<int>& R2) {
  return R1[0] == R2[0] && R1[1] == R2[1];
}

#define TEST(testCase) \
  assert(equal(Solution().threeEqualParts(testCase.A), testCase.R));

TestCase testCase1 = {{1,0,1,0,1}, {0,3}};
TestCase testCase2 = {{1,1,0,1,1}, {-1,-1}};
TestCase testCase3 = {{0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0}, {-1,-1}};

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  return 0;
}

