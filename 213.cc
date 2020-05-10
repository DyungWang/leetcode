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
    
    int dpp = max(nums[1], 0);
    int dpm = max(nums[2], nums[1]);
    int dpc = dpm;
    for (int i = 3; i < len; ++i) {
      dpc = max(dpp + nums[i], dpm);
      dpp = dpm;
      dpm = dpc;
    }

    int npp = max(nums[len-2], 0);
    int npm = max(nums[len-3], nums[len-2]);
    int npc = npm;
    for (int i = len-4; i >= 0; --i) {
      npc = max(npp + nums[i], npm);
      npp = npm;
      npm = npc;
    }
    return max(dpc, npc);
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

