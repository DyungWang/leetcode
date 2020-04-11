// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11
// @link https://leetcode.com/problems/permutation-sequence/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string str(n, '1');
    for (int i = 0; i < n; ++i)
      str[i] += i;
    permutation(str, 0, k-1);
    return str;
  }

 private:
  void permutation(string& str, int s, int k) {
    if (s == str.size())
      return;
    int m = factorial(str.size()-s-1);
    sort(str.begin()+s, str.end());
    swap(str[s], str[s+k/m]);
    permutation(str, s+1, k%m);
  }

  int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n-1);
  }
};

#define TEST(n, k, r) assert(Solution().getPermutation(n, k) == r);


int main(int, char**) {
  TEST(3, 3, "213");
  TEST(4, 9, "2314");
  return 0;
}
