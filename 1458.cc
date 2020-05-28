// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/28
// @link https://leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int mLen = nums1.size();
    int nLen = nums2.size();
    vector<vector<int>> dp(mLen+1, vector<int>(nLen+1, INT_MIN));
    for (int i = mLen-1; i >= 0; --i) {
      for (int j = nLen-1; j >= 0; --j) {
        int mul = nums1[i] * nums2[j];
        int pre = dp[i+1][j+1];
        dp[i][j] = pre < 0 ? max(mul, pre) : max(mul+pre, pre);
        dp[i][j] = max(dp[i][j], dp[i+1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j+1]);
      }
    }
    return dp[0][0];
  }
};

struct TestCase {
  vector<int> nums1;
  vector<int> nums2;
  int res;

  bool test() { return res == Solution().maxDotProduct(nums1, nums2); }
};

TestCase testCase1 = {
  {2,1,-2,5},
  {3,0,-6},
  18
};

TestCase testCase2 = {
  {3,-2},
  {2,-6,7},
  21
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}
