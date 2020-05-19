// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/18
// @link https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for (auto n : nums) {
      auto it = lower_bound(res.begin(), res.end(), n);
      if (it == res.end()) 
        res.push_back(n);
      else {
        *it = n;
      }
    }
    return res.size();
  }
};

struct TestCase {
  vector<int> nums;
  int length;
  
  bool test() { return length == Solution().lengthOfLIS(nums); }
};

TestCase testCase1 = {
  {10,9,2,5,3,7,101,18}, 4
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
