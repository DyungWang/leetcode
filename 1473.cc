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
    return ans;
  }
 
 private:
  int dfs(vector<int>& houses, vector<vector<int>>& cost, int target, int i) {
    if (target < 0) return -1;
    if (i == houses.size()) 
      return target == 0 ? 0 : -1;

    if (houses[i] != 0) {
      int nt = (i != 0 && houses[i-1] == houses[i]) ? target : (target-1);
      return dfs(houses, cost, nt, i+1);
    }

    int rr = -1;
    for (int j = 0; j < cost[i].size(); ++j) {
      houses[i] = j+1;
      int nt = (i != 0 && houses[i-1] == houses[i]) ? target : (target - 1);
      int nr = dfs(houses, cost, nt, i+1);
      if (nr == -1) continue;
      nr += cost[i][j];
      if (rr == -1 || nr < rr) rr = nr;
    }
    houses[i] = 0;
    return rr;
  }
};

struct TestCase {
  vector<int> houses;
  vector<vector<int>> cost;
  int m;
  int n;
  int target;
  int res;

  bool test() { return res == Solution().minCost(houses, cost, m, n, target); }
};

TestCase testCase1 = {
  {0,0,0,0,0},
  {{1,10},{10,1},{10,1},{1,10},{5,1}},
  5, 2, 3, 9
};

TestCase testCase2 = {
  {0,2,1,2,0},
  {{1,10},{10,1},{10,1},{1,10},{5,1}},
  5, 2, 3, 11
};

TestCase testCase3 = {
  {0,0,0,0,0},
  {{1,10},{10,1},{1,10},{10,1},{1,10}},
  5, 2, 5, 5
};

TestCase testCase4 = {
  {3,1,2,3},
  {{1,1,1},{1,1,1},{1,1,1},{1,1,1}},
  4, 3, 3, -1
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}
