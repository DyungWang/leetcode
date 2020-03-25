// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/03/25

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    priority_queue<int, vector<int>, greater<int>> que1;
    priority_queue<int, vector<int>, greater<int>> que2;
    int ans = 0;
    for (const auto& cost: costs) {
      if (cost[0] < cost[1]) {
        ans += cost[0];
        que1.push(cost[1] - cost[0]);
      } else {
        ans += cost[1];
        que2.push(cost[0] - cost[1]);
      }
    }
    if (que2.size() == que1.size())
      return ans;
    if (que1.size() <  que2.size())
      swap(que1, que2);
  
    while (que1.size() > costs.size() / 2) {
      ans += que1.top();
      que1.pop();
    }
    return ans; 
  }
};

vector<vector<int>> case1 = {
  {  10,  20 }, 
  {  30, 200 },
  { 400,  50 },
  {  30,  20 } 
};

vector<vector<int>> case2 = {
  { 259, 770 },
  { 448,  54 },
  { 926, 667 },
  { 184, 139 },
  { 840, 118 },
  { 577, 469 }
};

int main(int, char**) {
  Solution solution;
  // assert(solution.twoCitySchedCost(case1) == 110);
  solution.twoCitySchedCost(case2);
  return 0;
}
