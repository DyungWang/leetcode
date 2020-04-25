// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/25
// @link https://leetcode.com/problems/word-break/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size()+1, false);
    dp[s.size()] = true;
    for (int i = s.size()-1; i >= 0; --i) {
      for (int j = i+1; j <= s.size(); ++j) {
        dp[i] = dp[j] && words.count(s.substr(i, j-i)) > 0;
        if (dp[i]) break;
      }
    }
    return dp[0];
  }
};

struct TestCase {
  string s;
  vector<string> dict;
  bool r;

  bool test() { return r == Solution().wordBreak(s, dict); }
};

TestCase testCase1 = {
  "leetcode",
  { "leet", "code" },
  true
};

TestCase testCase2 = {
  "applepenapple",
  { "apple", "pen" },
  true
};

TestCase testCase3 = {
  "catsandog",
  { "cats", "dog", "sand", "and", "cat" },
  false
};

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  return 0;
}

