// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/21
// @link https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
 public:
  NumArray(vector<int>& nums)
      : nums_(nums.size(), 0),
        sums_(nums.size()+1, 0) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      update(i, nums[i]);
  }
  
  void update(int i, int val) {
    int diff = val - nums_[i];
    nums_[i] = val;
    int pos = i + 1;
    while (pos < static_cast<int>(sums_.size())) {
      sums_[pos] += diff;
      pos += (pos & -pos);
    }
  }
  
  int sumRange(int i, int j) {
    return getSum(j) - getSum(i-1);
  }
 
 private:
  int getSum(int i) {
    int sum = 0;
    int pos = i + 1;
    while (pos > 0) {
      sum += sums_[pos];
      pos -= (pos & -pos);
    }
    return sum;
  }
  
  vector<int> nums_;
  vector<int> sums_;
};

void test() {
  vector<int> nums = { 1, 3, 5 };
  NumArray array(nums);
  std::cout << array.sumRange(0, 2) << std::endl;
  array.update(1, 2);
  std::cout << array.sumRange(0, 2) << std::endl;
}

int main(int, char**) {
  test();
  return 0;
}
