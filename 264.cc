// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/14
// @link https://leetcode.com/problems/ugly-number-ii/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  #define tmin(x, y, z) min(x, min(y, z))
 public:
  int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    vector<int> nums(n);
    nums[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; ++i) {
      nums[i] = tmin(nums[p2]*2, nums[p3]*3, nums[p5]*5);
      if (nums[i] == nums[p2]*2) p2++;
      if (nums[i] == nums[p3]*3) p3++;
      if (nums[i] == nums[p5]*5) p5++;
    }
    return nums[n-1];
  }
};

struct TestCase {
  int n;
  int r;
  bool test() { return Solution().nthUglyNumber(n) == r; }
};

TestCase testCase1 = { 10, 12 };

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}


