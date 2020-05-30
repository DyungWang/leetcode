// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/30
// @link https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include "leetcode.h"

using namespace std;

class Solution {
 public:
  int maxVowels(string s, int k) {
    int w = 0;
    int r = 0;
    for (int i = 0; i < k && i < s.size(); ++i)
      w += isVowel(s[i]);
    r = w;
    for (int i = k; i < s.size(); ++i) {
      w = w + isVowel(s[i]);
      w = w - isVowel(s[i-k]);
      r = max(r, w);
    }
    return r;
  }

 private:
  inline int isVowel(char c) {
    if (c == 'a') return 1;
    if (c == 'e') return 1;
    if (c == 'i') return 1;
    if (c == 'o') return 1;
    if (c == 'u') return 1;
    return 0;
  }
};

struct TestCase {
  string s;
  int k;
  int r;
  bool test() { return r == Solution().maxVowels(s, k); }
};

TestCase testCase1 = {
  "abciiidef", 3, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
