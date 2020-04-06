#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int clumsy(int n) { 
    int r = clumsy(n, 1);
    do {
      n -= 4;
      r -= clumsy(n, -1);
    } while (n > 0);
    return r;
  }
 
 private:
  int clumsy(int n, int a) {
    if (n <= 0) return 0;
    if (n == 1) return 1; 
    if (n == 2) return 2; // 2 * 1 
    return n * (n-1) / (n-2) + a * (n-3);
  }
};

#define TEST_F(N, R) \
  assert(Solution().clumsy(N) == R);

int main(int, char**) {
  TEST_F(1,   1);
  TEST_F(4,   7);
  TEST_F(10, 12);
  return 0;
}
