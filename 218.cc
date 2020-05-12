// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/12
// @link https://leetcode.com/problems/the-skyline-problem/

#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> res;
    for (auto& bld: buildings) {
      if (res.empty()) {
        res.push_back({bld[0], bld[2]});
        res.push_back({bld[1], bld[2]});
        continue;
      } 
      vector<vector<int>> tmp;
      vector<int> pre = { 0, 0 };
      for (auto& pnt : res) {
        if (pre[0] < bld[0] && pnt[0] > bld[0]) {
          
        }
        
      }
    }
    return res;
  }
};
