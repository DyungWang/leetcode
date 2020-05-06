// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/06
// @link https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    bitset<32> mb(m);
    bitset<32> nb(n);
    bitset<32> rb(0);
    for (int i = max(msb(mb), msb(nb)); i >= 0; --i) {
      if (mb[i] ^ nb[i]) 
        break;
      rb[i] = mb[i];
    }
    return rb.to_ulong();
  }

 private:
   inline int msb(bitset<32>& bits) {
     for (int i = bits.size()-1; i >= 0; --i)
       if (bits[i] == 1) return i;
     return 0;
   }
};

struct TestCase {
  int m;
  int n;
  int r;

  bool test() { return r == Solution().rangeBitwiseAnd(m, n); }
};


TestCase testCase1 = { 5, 7, 4 };
TestCase testCase2 = { 0, 1, 0 };

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
#undef TEST
  return 0;
}

