// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/22
// @link https://leetcode.com/problems/distinct-subsequences/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    // dp[i][j] mean numDistinct(s[i::], t[j::]) 
    // if s[i] != s[j]:
    //    dp[i][j] = dp[i+1][j]
    // if s[i] == s[j]:
    //    dp[i][j] = dp[i+1][j] + dp[i+1][j+1]
    // dp[::][t.size()] = [1] * s.size()
    // dp[s.size()] = [0] * t.size()
    if (s.size() < t.size())
      return 0;
    if (s.size() == t.size())
      return s == t;
    int sLen = s.size();
    int tLen = t.size();
    vector<vector<int>> dp(sLen+1, vector<int>(tLen+1, 0));
    for (int j = 0; j <= tLen; ++j) dp[sLen][j] = 0;
    for (int i = 0; i <= sLen; ++i) dp[i][tLen] = 1;
    for (int i = sLen-1; i >= 0; --i) {
      int jend = max(tLen-sLen+i, 0);
      for (int j = tLen-1; j >= jend; --j) {
        dp[i][j] = dp[i+1][j] + (s[i] == t[j] ? dp[i+1][j+1] : 0);
      }
    }
    return dp[0][0];
  }
};

struct TestCase {
  string s;
  string t;
  int r;

  bool test() { return r == Solution().numDistinct(s, t); }
};

TestCase testCase1 = { "rabbbit", "rabbit", 3 };
TestCase testCase2 = { "babgbag", "bag", 5 };

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}

