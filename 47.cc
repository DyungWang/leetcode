// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/16
// @link https://leetcode.com/problems/permutations-ii/

#include <set>
#include <vector>
#include <iostream>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    permuteUnique(nums, 0, result);
    return result;
  }
 
 private:
  void permuteUnique(vector<int>& nums, int s, vector<vector<int>>& result) {
    if (s == nums.size()) {
      result.push_back(nums);
      return;
    }

    set<int> heads;
    for (int i = s; i < (int)nums.size(); ++i) {
      if (heads.count(nums[i]) != 0)
        continue;
      heads.insert(nums[i]);
      swap(nums[i], nums[s]);
      permuteUnique(nums, s+1, result);
      swap(nums[i], nums[s]);
    }
  }
};

struct TestCase {
  vector<int> input;
  vector<vector<int>> output;
};

bool test(TestCase& testCase) {
  vector<vector<int>> result;
  result = Solution().permuteUnique(testCase.input);
  return equal(result, testCase.output);
}

#define TEST(testCase) assert(test(testCase));

TestCase testCase1 = {
  { 1, 1, 2 },
  { 
    { 1, 1, 2 },
    { 1, 2, 1 },
    { 2, 1, 1 },
  }
};

TestCase testCase2 = {
  { 1, 1, 2, 2 },
  {
    { 1, 1, 2, 2 },
    { 1, 2, 1, 2 },
    { 1, 2, 2, 1 },
    { 2, 1, 1, 2 },
    { 2, 1, 2, 1 },
    { 2, 2, 1, 1 }
  }
};

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}
