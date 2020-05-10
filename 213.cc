// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/10
// @link https://leetcode.com/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];
    if (len == 2) return max(nums[0], nums[1]);
    
    vector<int> dp(nums.size(), 0);
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 2; i < len; ++i)
      dp[i] = max(nums[i]+dp[i-2], dp[i-1]);

    vector<int> np(nums.size(), 0);
    np[len-2] = nums[len-2];
    np[len-3] = max(nums[len-2], nums[len-3]);
    for (int i = len-4; i >= 0; --i)
      np[i] = max(nums[i]+np[i+2], np[i+1]);

    return max(dp[len-1], np[0]);
  }
};

struct TestCase {
  vector<int> nums;
  int res;

  bool test() { return res == Solution().rob(nums); }
};

TestCase testCase1 = { { 2, 3, 2 }, 3 };
TestCase testCase2 = { { 1, 2, 3, 1 }, 4 };

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
#undef TEST
  return 0;
}

