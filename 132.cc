// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/22
// @link https://leetcode.com/problems/palindrome-partitioning-ii/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  int minCut(string s) {
    vector<vector<int>> leftMap(s.size());
    for (int i = 0; i < s.size(); ++i) {
      palindrome(s, i, i,   leftMap);
      palindrome(s, i, i+1, leftMap);
    }
    return bfs(leftMap) - 1;
  }

 private:
  inline void palindrome(const string& s, int l, int r, 
      vector<vector<int>>& leftMap) {
    while (l >= 0 && r < s.size() && s[l] == s[r])
      leftMap.at(l--).push_back(r++);
  }

  inline int bfs(vector<vector<int>>& leftMap) {
    vector<int> visited(leftMap.size()+1, 0);
    vector<int> todos(1, 0);
    visited[0] = 1;
    int ret = 0;
    while (!todos.empty()) {
      vector<int> nexts;
      for (auto l : todos) {
        if (l >= leftMap.size()) 
          return ret;
        for (auto r : leftMap[l]) if (!visited[r+1]) {
          nexts.push_back(r+1);
          visited[r+1] = 1;
        }
      }
      swap(todos, nexts);
      ret++;
    }
    return ret;
  }
};

struct TestCase {
  string s;
  int r;

  bool test() { return r == Solution().minCut(s); }
};

TestCase testCase1 = {
  "aab",
  1
};

TestCase testCase2 = {
  "aaab",
  1,
};


#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}

