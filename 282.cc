// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/17
// @link https://leetcode.com/problems/expression-add-operators/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    if (num.length() == 0)
      return {};
    vector<string> res;
    string r; 
    r.reserve(num.size()*2);
    dfs(num, 0, target, 0, 0, r, res);
    return res;
  }
 
 private:
  void dfs(string& num, int i, int t, int64_t s, int64_t p, string& r, vector<string>& res) {
    if (i == num.size()) {
      if (s == t)
        res.push_back(r);
      return;
    }

    int64_t n = 0;
    int64_t q = r.size();
    if (i != 0) r.push_back('+');
    for (int j = i; j < num.size(); ++j) {
      r.push_back(num[j]);
      n = n * 10 + num[j] - '0';
      if (i != j && num[i] == '0')
        break;
      if (i == 0) {
        dfs(num, j+1, t, s+n, n, r, res);
        continue;
      }
      r[q] = '+';
      dfs(num, j+1, t, s+n, n, r, res);
      r[q] = '-';
      dfs(num, j+1, t, s-n, -n, r, res);
      r[q] = '*';
      dfs(num, j+1, t, s-p+p*n, p*n, r, res);
    }
    while (r.size() > q) r.pop_back();
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
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}




