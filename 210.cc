// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/07
// @link https://leetcode.com/problems/course-schedule-ii/

#include <iostream>
#include <vector>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int num, vector<vector<int>>& pres) {
    vector<vector<int>> nexts(num);
    vector<bool> hasPre(num, false);
    for (auto& kv : pres) {
      nexts[kv[1]].push_back(kv[0]);
      hasPre[kv[0]] = true;
    }

    vector<int> visit(num, 0);
    vector<int> order; order.reserve(num);
    for (int i = 0; i < num; ++i) {
      if (hasPre[i]) continue;
      vector<int> curpr(num, 0);
      if (hasCycle(nexts, curpr, i))
        return {};
      dfs(nexts, visit, order, i);
    }
    if (order.size() < num) 
      return {};
    reverse(order.begin(), order.end());
    return order;
  }

 private:
  inline void dfs(vector<vector<int>>& nexts, vector<int>& visit, vector<int>& order, int i) {
    if (visit[i]) return;
    visit[i] = 1;
    for (auto n : nexts[i]) 
      dfs(nexts, visit, order, n);
    order.push_back(i);
  }

  inline bool hasCycle(vector<vector<int>>& nexts, vector<int>& curpr, int i) {
    if (curpr[i]) return true;
    curpr[i] = 1;
    for (auto n : nexts[i]) if (hasCycle(nexts, curpr, n))
      return true;
    curpr[i] = 0;
    return false;
  }
};

struct TestCase {
  int num;
  vector<vector<int>> pres;
  vector<int> res;

  bool test() {
    return equal(res, Solution().findOrder(num, pres));
  }
};

TestCase testCase1 = {
  2, 
  { {1, 0} },
  { 0, 1 }
};

TestCase testCase2 = {
  4, 
  { {1, 0}, { 2, 0 }, { 3, 1 }, { 3, 2 } },
  { 0, 2, 1, 3 }
};

TestCase testCase3 = {
  3,
  { { 1, 0 }, { 1, 2 }, { 0, 1 } },
  { } 
};

TestCase testCase4 = {
  8,
  {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}},
  {}
};


int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  // TEST(testCase2);
  // TEST(testCase3);
  TEST(testCase4);
#undef TEST
  return 0;
}
