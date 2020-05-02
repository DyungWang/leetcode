// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/02
// @link https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string fractionToDecimal(int num, int den) {
    if (num == 0) 
      return "0";
    int64_t bef = abs(num) / abs(den);
    int64_t aft = abs(num) % abs(den);
    unordered_map<int64_t, int64_t> epos;
    vector<int64_t> afts;

    string res;
    while (aft != 0) {
      auto iter = epos.find(aft);
      if (iter != epos.end()) {
        res = recycle(bef, iter->second, afts);
        break;
      }
      epos[aft] = afts.size();
      afts.push_back(aft * 10 / abs(den));
      aft = aft * 10 % den;
    }
    if (res.empty())
      res = unrecycle(bef, afts);
    if ((num < 0 && den > 0) || (num > 0 && den < 0))
      res = "-" + res;
    return res;
  }

 private:
  inline string recycle(int64_t bef, int64_t rep, vector<int64_t>& afts) {
    string res = to_string(bef) + ".";
    for (int i = 0; i < rep; ++i)
      res += to_string(afts[i]);
    res += "(";
    for (int i = rep; i < afts.size(); ++i) 
      res += to_string(afts[i]);
    res += ")";
    return res;
  }

  inline string unrecycle(int64_t bef, vector<int64_t>& afts) {
    string res = to_string(bef);
    if (afts.empty())
      return res;
    res += ".";
    for (auto aft : afts) 
      res += to_string(aft);
    return res;
  }
};

struct TestCase {
  int num;
  int den;
  string res;

  bool test() { return res == Solution().fractionToDecimal(num, den); }
};

TestCase testCase1 = {
  1, 2, "0.5"
};

TestCase testCase2 = {
  2, 1, "2"
};

TestCase testCase3 = {
  2, 3, "0.(6)"
};

TestCase testCase4 = {
  7, -12, "-0.58(3)"
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
    TEST(testCase1);
    TEST(testCase2);
    TEST(testCase3);
    TEST(testCase4);
  #undef TEST
  return 0;
}

