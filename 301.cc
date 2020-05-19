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
    string r; r.reserve(s.size());
    dfs(s, 0, lcnt, rcnt, 0, r, res);
    return { res.begin(), res.end() };
  }
 
 private:
  void dfs(string& s, int i, int lcnt, int rcnt, int pair, string& r, unordered_set<string>& res) {
    if (i == s.size()) {
      if (lcnt == 0 && rcnt == 0 && pair == 0) 
        res.insert(r);
      return;
    }
    if (s[i] == '(' && lcnt > 0)
      dfs(s, i+1, lcnt-1, rcnt, pair, r, res);
    if (s[i] == ')' && rcnt > 0)
      dfs(s, i+1, lcnt, rcnt-1, pair, r, res);
    
    r.push_back(s[i]);
    if (s[i] != '(' && s[i] != ')')
      dfs(s, i+1, lcnt, rcnt, pair, r, res);
    else if (s[i] == '(')
      dfs(s, i+1, lcnt, rcnt, pair+1, r, res);
    else if (pair > 0)
      dfs(s, i+1, lcnt, rcnt, pair-1, r, res);
    r.pop_back();
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
