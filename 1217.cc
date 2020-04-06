// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/06
// @link https://leetcode.com/problems/play-with-chips/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCostToMoveChips(vector<int>& chips) {
    int eventCount = 0;
    for (auto pos: chips) if (pos % 2 == 0)
      eventCount++;
    return min(eventCount, (int)chips.size()-eventCount);
  }
};
