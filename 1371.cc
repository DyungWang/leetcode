// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/04

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
 public:
  int findTheLongestSubstring(string s) {
    // 这个解释非常好 
    // https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/531840/JavaC%2B%2BPython-One-Pass
    const static string vowels = "aeiou";
    map<int, int> posMap = {{0, -1}};
    int cur = 0;
    int res = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      auto pos = vowels.find(s[i]);
      if (pos != string::npos) 
        cur ^= 1 << pos;
      if (posMap.count(cur) == 0)
        posMap[cur] = i;
      res = max(res, i - posMap[cur]);
    }
    return res;
  }
};

struct TestCase {
  string input;
  int output;
};

TestCase case1 = { "eleetminicoworoep", 13 };
TestCase case2 = { "leetcodeisgreat", 5 };
TestCase case3 = { "bcbcbc", 6 };

int main(int, char**) {
  Solution solution;
  assert(solution.findTheLongestSubstring(case1.input) == case1.output);
  assert(solution.findTheLongestSubstring(case2.input) == case2.output);
  assert(solution.findTheLongestSubstring(case3.input) == case3.output);
  return 0;
}

