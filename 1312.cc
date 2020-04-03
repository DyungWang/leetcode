#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minInsertions(string s) {
    vector<vector<int>> dis(s.size()+1, vector<int>(s.size()+1, 0));
    string r = s; reverse(r.begin(), r.end());
    int res = INT32_MAX;
    for (int i = s.size()-1; i >= 0; --i) {
      for (int j = s.size()-1; j >= 0; --j) {
        dis[i][j] = dis[i+1][j+1] + (s[i] == r[j]);
        dis[i][j] = max(dis[i][j], max(dis[i+1][j], dis[i][j+1]));
      }
      // 0 -> i, i   -> len  => i + j = len - 1
      // 0 -> i, i+1 -> len  => i + j = len
      res = min(res, (int)s.size() + 1 - dis[i][s.size()-1-i]*2); // two same.
      res = min(res, (int)s.size() - dis[i][s.size()-i]*2);
    }
    return res;
  }
};

struct TestCase {
  string input;
  int output;
};

TestCase case1 = { "zzazz", 0 };
TestCase case2 = { "mbadm", 2 };
TestCase case3 = { "leetcode", 5 };
TestCase case4 = { "g", 0 };
TestCase case5 = { "zjveiiwvc", 5 };

int main(int, char**) {
  Solution solution;
  assert(solution.minInsertions(case1.input) == case1.output);
  assert(solution.minInsertions(case2.input) == case2.output);
  assert(solution.minInsertions(case3.input) == case3.output);
  assert(solution.minInsertions(case4.input) == case4.output);
  assert(solution.minInsertions(case5.input) == case5.output);
  return 0;
}
