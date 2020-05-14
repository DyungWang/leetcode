// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/14
// @link https://leetcode.com/problems/ugly-number-ii/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int64_t> nums;
    for (int64_t a = 1; a <= INT_MAX; a *= 5) {
      for (int64_t b = a; b <= INT_MAX; b *= 3) {
        for (int64_t c = b; c <= INT_MAX; c *= 2) {
          nums.push_back(c);
        }
      }
    }
    sort(nums.begin(), nums.end());
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


