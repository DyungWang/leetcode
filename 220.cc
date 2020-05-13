// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/12
// @link https://leetcode.com/problems/contains-duplicate-iii/

#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (t <  0) return false;
    if (k <= 0) return false;
    set<int64_t> win;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (containInrange(win, nums[i], t))
        return true;
      if (i >= k) 
        win.erase(nums[i-k]);
      win.insert(nums[i]);
    }
    return false;
  } 
  
 private:
  bool containInrange(set<int64_t>& win, int64_t n, int64_t w) {
    auto iter = win.lower_bound(n - w);
    if (iter == win.end())
      return false;
    return abs(*iter - n) <= w;
  }
};

struct TestCase {
  vector<int> nums;
  int k;
  int t;
  int r;

  bool test() { return r == Solution().containsNearbyAlmostDuplicate(nums, k, t); }
};

TestCase testCase1 = {
  {1,2,3,1}, 3, 0, 1
};

TestCase testCase2 = {
  {1,0,1,1}, 1, 2, 1
};

TestCase testCase3 = {
  {1,5,9,1,5,9}, 2, 3, 0
};

TestCase testCase4 = {
  {2, 1}, 1, 1, 1
};

TestCase testCase5 = {
  {1,5,9,1,5,9}, 2, 3, 0
};

TestCase testCase6 = {
  {1, 2}, 0, 1, 0
};

TestCase testCase7 = {
  {-3, 3}, 2, 4, 0
};

TestCase testCase8 = {
  {0,2147483647}, 1, 2147483647, 1
};

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  TEST(testCase5);
  TEST(testCase6);
  TEST(testCase7);
  TEST(testCase8);
#undef TEST
  return 0;
}




