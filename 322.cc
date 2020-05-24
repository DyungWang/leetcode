// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/24
// @link https://leetcode.com/problems/coin-change/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= amount; ++i) {
      for (int c : coins) {
        int j = i - c;
        if (j <  0 || dp[j] == INT_MAX) 
          continue;
        dp[i] = min(dp[i], dp[j]+1);
      }
    }
    if (dp[amount] == INT_MAX)
      return -1;
    return dp[amount];
  }
};

struct TestCase {
  vector<int> coins;
  int amount;
  int count;
  bool test() { return count == Solution().coinChange(coins, amount); }
};

TestCase testCase1 = {
  {1, 2, 5}, 11, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
