// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/11
// @link https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    auto iter = nums.begin() + nums.size() - k;
    nth_element(nums.begin(), iter, nums.end());
    return *iter;
  }
};

struct TestCase {
  vector<int> nums;
  int k;
  int r;

  bool test() { return r == Solution().findKthLargest(nums, k); }
};

TestCase testCase1 = {
  {3,2,1,5,6,4}, 2, 5
};

TestCase testCase2 = {
  {3,2,3,1,2,4,5,5,6}, 4, 4
};

TestCase testCase3 = {
  {2, 1}, 2, 1
};

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
#undef TEST
  return 0;
}
