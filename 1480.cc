// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/17
// @link https://leetcode.com/problems/running-sum-of-1d-array/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> sums; 
    sums.reserve(nums.size());
    int sum = 0;
    for (auto n : nums) {
      sum += n;
      sums.push_back(sum);
    }
    return sums;
  }
};
