// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/17
// @link https://leetcode.com/problems/divide-two-integers/

#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;
    int64_t a = abs(dividend);
    int64_t b = abs(divisor);
    int64_t m = 0;
    int64_t r = 0;
    while (b <= a) {
      m = findMin(a, b);
      a -= b << m;
      r += 1 << m;
    }
    return (dividend > 0) == (divisor > 0) ? r : -r;
  }

 private:
  inline int findMin(int64_t a, int64_t b) {
    int r = 1;
    while ((b << r) < a) ++r;
    return r-1;
  }
};

#define TEST(a, b, r) assert(Solution().divide(a, b) == r);

int main(int, char**) {
  TEST(10, 3, 3);
  TEST(7, -3, -2);
  return 0;
}

