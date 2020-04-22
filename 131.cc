// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/22
// @link https://leetcode.com/problems/palindrome-partitioning/

#include <string>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<int>> leftMap(s.size());
    for (int i = 0; i < s.size(); ++i) {
      palindrome(s, i, i,   leftMap);
      palindrome(s, i, i+1, leftMap);
    }
    vector<vector<string>> result;
    vector<string> part;
    dfs(0, s, part, leftMap, result);
    return result;
  }

 private:
  inline void palindrome(const string& s, int l, int r, 
      vector<vector<int>>& leftMap) {
    while (l >= 0 && r < s.size() && s[l] == s[r])
      leftMap.at(l--).push_back(r++);
  }

  inline void dfs(int i, 
      string& s,
      vector<string>& part,
      vector<vector<int>>& leftMap, 
      vector<vector<string>>& result) {
    if (i >= s.size()) {
      result.push_back(part);
      return;
    }
    for (auto r : leftMap[i]) {
      part.push_back(s.substr(i, r-i+1));
      dfs(r+1, s, part, leftMap, result);
      part.pop_back();
    }
  }
};

struct TestCase {
  string s;
  vector<vector<string>> r;

  bool test() { return equal(r, Solution().partition(s)); }
};

TestCase testCase1 = {
  "aab",
  {
    { "a", "a", "b" },
    { "aa", "b" }
  }
};

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

