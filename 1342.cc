#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSteps(int num) {
    int cnt = 0;
    while (num > 0) {
      num = num & 1 ? (num - 1) : (num / 2);
      cnt = cnt + 1;
    }
    return cnt;
  }
};

#define TEST(n, r) assert(Solution().numberOfSteps(n) == r);

int main(int, char**) {
  TEST( 14,  6);
  TEST(  8,  4);
  TEST(123, 12);
  return 0;
}
