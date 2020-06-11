// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/11
// @link https://leetcode.com/problems/paint-house-iii/

#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, 
      int m, int n, int target) {
    int ans = dfs(houses, cost, target, 0);
    if (ans == -1) 
      return -1;
    for (int i = 0; i < houses.size(); ++i)
      ans += houses[i] == 0 ? 0 : cost[i][houses[i]];
    return ans;
  }
 
 private:
  int dfs(vector<int>& houses, vector<vector<int>>& cost, int target, int i) {
    if (target < 0) return -1;
    if (i == houses.size()) 
      return target == 0 ? 0 : -1;

    if (houses[i] != 0) {
      int nt = (i != 0 && houses[i-1] == houses[i]) ? target : (target-1);
      return dfs(houses, paint, cost, nt, i+1);
    }

    int rr = INT_MAX;
    for (int j = 0; j < cost[i].size(); ++j) {
      houses[i] = j+1;
      int nt = (i != 0 && houses[i-1] == houses[i]) ? target : (target - 1);
      int nr = dfs(houses, paint, cost, nt, i+1);
      if (nr == -1) continue;
      nr += cost[i][j];
      if (rr == -1 || nr < rr) rr = nr;
    }
    houses[i] = 0;
    return r;
  }
};

struct TestCase {
  
};
