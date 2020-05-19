// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/19
// @link https://leetcode.com/problems/remove-invalid-parentheses/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int32_t lcnt = 0, rcnt = 0;
    for (auto c : s) {
      if (c == '(') lcnt++;
      if (c == ')' && lcnt == 0) rcnt++;
      if (c == ')' && lcnt >  0) lcnt--; 
    }
    unordered_set<string> res;
    dfs(s, 0, lcnt, rcnt, 0, "", res);
    return { res.begin(), res.end() };
  }
 
 private:
  void dfs(string& s, int i, int lcnt, int rcnt, int pair, string r, unordered_set<string>& res) {
    if (i == s.size()) {
      if (lcnt == 0 && rcnt == 0 && pair == 0) 
        res.insert(r);
      return;
    }
    if (s[i] != ')' && s[i] != '(') {
      dfs(s, i+1, lcnt, rcnt, pair, r+s[i], res);
      return;
    } 

    if (s[i] == '(') {
      if (lcnt > 0)
        dfs(s, i+1, lcnt-1, rcnt, pair, r, res);
      dfs(s, i+1, lcnt, rcnt, pair+1, r+s[i], res);
    } 
    if (s[i] == ')') {
      if (rcnt > 0)
        dfs(s, i+1, lcnt, rcnt-1, pair, r, res);
      if (pair > 0)
        dfs(s, i+1, lcnt, rcnt, pair-1, r+s[i], res);
    }
  }
};

struct TestCase {
  string s;
  vector<string> r;

  bool test() { return equal(r, Solution().removeInvalidParentheses(s)); }
};

TestCase testCase1 = {
  "()())()",
  { "()()()", "(())()" }
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
