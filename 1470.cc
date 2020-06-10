// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/10
// @link https://leetcode.com/problems/shuffle-the-array/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2*n);
    for (int i = 0; i < n; ++i) {
      ans[2*i+0] = nums[i];
      ans[2*i+1] = nums[n+i];
    }
    return ans;
  }
};
