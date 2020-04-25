// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/25
// @link https://leetcode.com/problems/word-break-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<vector<int>> dp(s.size()); 
    for (int i = s.size(); i >= 0; --i) {
      for (int j = i+1; j < s.size();  ++j) {
        if (dp[j].empty()) 
          continue;
        if (words.count(s.substr(i, j-i)) != 0) 
          dp[i].push_back(j);
      }
      if (words.count(s.substr(i)) != 0) 
        dp[i].push_back(s.size());
    }

    vector<string> outs;
    dfs(s, dp, 0, "", outs);
    return outs;
  }
 
 private:
  void dfs(string& s, vector<vector<int>>& next, 
      int i, string out, vector<string>& outs) {
    if (i == next.size()) {
      outs.push_back(out);
      return;
    }
    for (auto j : next[i]) {
      string q = (i == 0 ? "" : " ") + s.substr(i, j-i);
      dfs(s, next, j, out + q, outs);
    }
  }
};

struct TestCase {
  string s;
  vector<string> dict;
  vector<string> outs;

  bool test() { return equal(outs, Solution().wordBreak(s, dict)); }
};

TestCase testCase1 = {
  "catsanddog",
  { "cat", "cats", "and", "sand", "dog" },
  {
    "cats and dog",
    "cat sand dog"
  }
};


#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  return 0;
}



