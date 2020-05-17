// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/17
// @link https://leetcode.com/problems/expression-add-operators/

#include <vector>
#include <string>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(num, target, 0, 0, 0, "", res);
    return res;
  }
 
 private:
  void dfs(string& num, int t, int s, int64_t cv, int64_t pv, string r, vector<string>& res) {
    if (s == num.size() && cv == t) {
      res.push_back(r);
      return;
    }
    for (int i = s+1; i <= num.size(); ++i) {
      if (num[s] == '0' && i-s > 1) 
        continue;
      string ns = num.substr(s, i-s);
      int64_t n = stoll(ns);
      if (s == 0) {
        dfs(num, t, i, n, n, ns, res);
        continue;
      }
      dfs(num, t, i, cv+n,  n, r+"+"+ns, res);
      dfs(num, t, i, cv-n, -n, r+"-"+ns, res);
      dfs(num, t, i, cv-pv+pv*n, pv*n, r+"*"+ns, res);
    }
  }
};

struct TestCase {
  string num;
  int target;

  vector<string> res;

  bool test() { return  equal(res, Solution().addOperators(num, target)); }
};

TestCase testCase1 = {
  "123", 6, {"1+2+3", "1*2*3"}
};

TestCase testCase2 = {
  "232", 8, {"2+3*2", "2*3+2"}
};

TestCase testCase3 = {
  "105", 5, {"1*0+5", "10-5"}
};

TestCase testCase4 = {
  "2147483647", 2147483647, {"2147483647"}
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  // TEST(testCase2);
  // TEST(testCase3);
  TEST(testCase4);
  return 0;
}




