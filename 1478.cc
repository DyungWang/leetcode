// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/17
// @link https://leetcode.com/problems/allocate-mailboxes/

#include <vector>

using namespace std;

class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    int n = houses.size();
    sort(houses.begin(), houses.end());
    // start at i, end at j, the mean distance for these houses.
    vector<vector<int>> costs(n, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) for (int j = i+1; j <= n; ++j) {
      int m = (i + j - 1) / 2;
      for (int t = i; t < j; ++t) 
        costs[i][j] += abs(houses[t] - houses[m]);
    }
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return dfs(costs, dp, 0, k);
  }

 private:
  // find the min distance of house[s->end) with k boxs 
  int dfs(vector<vector<int>>& costs, vector<vector<int>>& dp, int s, int k) {
    if (s >= dp.size()) return 0;
    if (k == 0) return -1; // there no box there.
    if (dp[s][k] >= 0) return dp[s][k];

    // now find min distance of s, k
    int ans = -1;
    for (int i = s+1; i <= dp.size(); ++i) {
      int tmp = dfs(costs, dp, i, k-1);
      if (tmp < 0) continue;
      tmp = tmp + costs[s][i];
      ans = ans >= 0 ? min(ans, tmp) : tmp;
    }
    return (dp[s][k] = ans);
  }
};

struct TestCase {
  vector<int> houses;
  int k;
  int r;
  bool test() { return r == Solution().minDistance(houses, k); }
};

TestCase testCase1 = {
  {1,4,8,10,20}, 3, 5
};

TestCase testCase2 = {
  {2,3,5,12,18}, 2, 9
};

TestCase testCase3 = {
  {7,4,6,1}, 1, 8
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  return 0;
}
