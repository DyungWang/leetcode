#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    return min(decreasing(nums, 0), decreasing(nums, 1));
  }

  int decreasing(const vector<int>& nums, int s) {
    int res = 0;
    for (int i = s; i < nums.size(); i += 2) {
      int ldec = 0;
      int rdec = 0;
      if (i-1 >= 0 && nums[i] >= nums[i-1])
        ldec = nums[i] - nums[i-1] + 1;
      if (i+1 < nums.size() && nums[i] >= nums[i+1])
        rdec = nums[i] - nums[i+1] + 1;
      res += max(ldec, rdec);
    }
    return res;
  }
};

struct TestCase {
  vector<int> nums;
  int result;
};

TestCase testCase1 = { { 1, 2, 3 }, 2 };
TestCase testCase2 = { { 9, 6, 1, 6, 2 }, 4 };

#define TEST_F(testCase) assert(Solution().movesToMakeZigzag(testCase.nums) == testCase.result);

int main(int, char**) {
  TEST_F(testCase1);
  TEST_F(testCase2);
  return 0;
}
