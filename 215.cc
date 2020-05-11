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
    return findKthLargest(nums.begin(), nums.end(), k);
  }

 private:
  int findKthLargest(Iter begin, Iter end, int k) {
    Iter l = begin, r = end - 1;
    while (l < r) {
      while (*r >  *begin && l < r) --r;
      while (*l <= *begin && l < r) ++l;
      swap(*l, *r);
    }
    if (*r < *begin) swap(*r, *begin);

    int t = end - r; 
    if (t == k) return *r;
    if (t <  k) 
      return findKthLargest(begin, r, k-t);
    return findKthLargest(r+1, end, k);
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
