#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minInsertions(string s) {
    // 使用 cnt[i][j] 来保存从 s[0:i], reverse(s[j::]) 中最多顺序相同的元素个数
    // 显然对于 cnt[i][j]来说，有：
    // s[i-1] == s[j]：
    //    cnt[i][j] = max(cnt[i-1][j+1]+1, cnt[i-1][j], cnt[i][j+1])
    // s[i-1] != s[j]:
    //    cnt[i][j] = max(cnt[i-1][j+1], cnt[i-1][j], cnt[i][j+1])
    vector<vector<int>> cnt(s.size()+1, vector<int>(s.size()+2, 0));
    int res = INT32_MAX;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = s.size()-1; j >= i; --j) {
        int d1 = cnt[i-1][j  ];
        int d2 = cnt[i  ][j+1];
        int d3 = cnt[i-1][j+1] + (s[i-1] == s[j]);
        cnt[i][j] = max(d1, max(d2, d3));
      }
      // s[0:i], reserve(s[i  ::]) 0->i-1, i   -> len
      // s[0:i], reserve(s[i+1::]) 0->i-1, i+1 -> len
      res = min(res, (int)s.size() - 2 * cnt[i][i  ]    );
      res = min(res, (int)s.size() - 2 * cnt[i][i+1] - 1);
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
