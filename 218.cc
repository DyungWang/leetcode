// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/12
// @link https://leetcode.com/problems/the-skyline-problem/

#include <vector>
#include <map>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    map<int, int> points; 
    points.insert({-1, 0});

    for (auto bld : buildings) {
      auto rl = bld[0];
      auto rr = bld[1];
      auto rh = bld[2];
      auto ph = 0;
      auto iter = points.upper_bound(bld[0]);
      if ((--iter)->first < rl && iter->second < rh) {
        ph = iter->second;
        iter = ++points.insert({rl, rh}).first;
      }
      for (; iter != points.end() && iter->first < rr; ++iter) {
        ph = iter->second;
        iter->second = max(iter->second, rh);
      }
      if (ph < rh) points.insert({rr, ph});
    }

    vector<vector<int>> res;
    vector<int> pre({-1, 0});
    for (auto& kv : points) {
      if (kv.second == pre[1])
        continue;
      pre[0] = kv.first;
      pre[1] = kv.second;
      res.push_back(pre);
    }
    return res;
  }
};

struct TestCase {
  vector<vector<int>> buildings;
  vector<vector<int>> result;
  bool test() { return equal(result, Solution().getSkyline(buildings)); }
};

TestCase testCase1 = {
  { 
    { 2,  9, 10}, 
    { 3,  7, 15}, 
    { 5, 12, 12}, 
    {15, 20, 10}, 
    {19, 24,  8}
  },
  {
    {2,10}, {3,15}, {7,12}, {12,0}, {15,10}, {20,8}, {24,0}
  }
};

int main(int, char**) {
  testCase1.test();
}
