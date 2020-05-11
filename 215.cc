// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/11
// @link https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  typedef vector<int>::iterator Iter;
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return findKthLargest(nums, 0, nums.size(), k);
  }

 private:
  int findKthLargest(vector<int>& nums, int b, int e, int k) {
    if (b >= e) return -1; // error
    if (k == 0 || k > e-b) return -1; // error
    int l = b, r = e - 1;
    while (l < r) {
      while (nums[r]  > nums[b] && l < r) --r;
      while (nums[l] <= nums[b] && l < r) ++l;
      swap(nums[l], nums[r]);
    }
    if (nums[r] < nums[b]) swap(nums[r], nums[b]);

    int t = e - r; 
    if (t == k) return nums[r];
    if (t <  k) 
      return findKthLargest(nums, b, r, k-t);
    return findKthLargest(nums, r+1, e, k);
  }
};
d
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
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
#undef TEST
  return 0;
}
