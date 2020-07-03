// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/25
// @link https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (m > bloomDay.size() / k) 
      return -1;
    multiset<int, greater<int>> win(bloomDay.begin(), bloomDay.begin()+k-1);
    vector<int> waitDays(bloomDay.size()-k+1);
    for (int i = 0; i < waitDays.size(); ++i) {
      win.insert(bloomDay[i+k-1]);
      waitDays[i] = *(win.begin());
      win.erase(bloomDay[i]);
    }
    vector<vector<int>> dp(waitDays.size(), vector<int>(m+1, -1));
    return dfs(waitDays, dp, 0, m, k);
  }

 private:
  int dfs(vector<int>& waitDays, vector<vector<int>>& dp, int s, int m, int k) {
    if (m <= 0) return 0;
    if (s >= waitDays.size()) return -1;
    if (dp[s][m] >= 0) return dp[s][m];
    int ans = -1;
    int mwt = INT_MAX;
    for (int i = s; i < waitDays.size(); ++i) {
      mwt = min(mwt, waitDays[i]);
      int tmp = dfs(waitDays, dp, i+k, m-1, k);
      if (tmp < 0) continue;
      tmp = max(tmp, mwt);
      ans = ans < 0 ? tmp : min(ans, tmp);
    }
    return (dp[s][m] = ans);
  }
};

struct TestCase {
  vector<int> bloomDay;
  int m;
  int k;
  int r;

  bool test() { return r == Solution().minDays(bloomDay, m, k); }
};

TestCase testCase1 = {
  {1,10,3,10,2}, 3, 1, 3
};

TestCase testCase2 = {
  {1,10,3,10,2}, 3, 2, -1
};

TestCase testCase3 = {
  {7,7,7,7,12,7,7}, 2, 3, 12
};

TestCase testCase4 = {
  {79,30,15,94,80,52,14,4,81,62,40,47,44,98,73,63,36,1,66,83,66,36,35,64,45,21,76,4,79,36,57,20,86,15,19},
  35, 1, -1
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  // TEST(testCase2);
  // TEST(testCase3);
  TEST(testCase4);
  return 0;
}

