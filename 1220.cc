#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int countVowelPermutation(int n) {
    // A[i] number of length i string end with a
    // E[i] number of length i string end with e
    // I[i] number of length i string end with i
    // O[i] number of length i string end with o
    // U[i] number of length i string end with u
    // A[i+1] = E[i] + I[i] + U[i] 
    // E[i+1] = A[i] + I[i]
    // I[i+1] = E[i] + O[i]
    // O[i+1] = I[i]
    // U[i+1] = I[i] + O[i]
    if (n == 0) return 0;
    int64_t A = 1, a = 1; 
    int64_t E = 1, e = 1;
    int64_t I = 1, i = 1;
    int64_t O = 1, o = 1;
    int64_t U = 1, u = 1;
    int64_t m = pow(10, 9) + 7;
    while (--n > 0) {
      A = (e + i + u) % m;
      E = (a + i) % m;
      I = (e + o) % m;
      O = i;
      U = (i + o) % m;
      a = A; e = E; i = I; o = O; u = U; 
    }
    return (A + E + I + O + U) % m;
  }
};

#define TEST_F(n, r) assert(Solution().countVowelPermutation(n) == r);

int main(int, char**) {
  TEST_F(1, 5);
  TEST_F(2, 10);
  TEST_F(5, 68);
  return 0;
}
