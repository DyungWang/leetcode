// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/03/24

#include <iostream>
#include <cstdint>
#include <assert.h>

using namespace std;

// ans = len ^ 10 + ans
// ans % K = (len ^ 10) % K + ans % K = (((len - 1) ^ 10) % K ) * 10) % K + ans % K
//
// let stp = (stp * 10) % K
// ans = stp + ans % K
// 
// stp0 = 1;
// ans0 = 1;
// len0 = 1;

class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    if (K % 2 == 0) return -1;
    if (K % 5 == 0) return -1;
    int len = 1;
    int ans = 1;
    int stp = 1;   
    while (ans % K != 0) {
      stp = (stp * 10) % K;
      ans = (ans % K) + stp;
      len++;
    }
    return len;
  }
};

int main(int, char**) {
  Solution solution;
  assert(solution.smallestRepunitDivByK(1) ==  1);
  assert(solution.smallestRepunitDivByK(3) ==  3);
  assert(solution.smallestRepunitDivByK(2) == -1);
  assert(solution.smallestRepunitDivByK(4) == -1);
  return 0;
}
