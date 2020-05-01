// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/01
// https://leetcode.com/problems/maximum-gap/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int minv = findMin(nums);
    int maxv = findMax(nums);
    if (minv == maxv) return 0;

    int blen = ceil((double)(maxv - minv) / (nums.size()-1.0));
    int bcnt = ceil((double)(maxv - minv) / blen) + 1;
    
    vector<vector<int>> bucket(bcnt); // bucket min, max
    for (auto n: nums) {
      int bpos = (n - minv) / blen;
      if (bucket[bpos].empty()) {
        bucket[bpos] = { n, n };
      } else {
        bucket[bpos][0] = min(bucket[bpos][0], n);
        bucket[bpos][1] = max(bucket[bpos][1], n);
      }
    }

    int mgap = blen;
    int pmax = minv;
    for (auto& blk: bucket) {
      if (blk.empty())
        continue;
      mgap = max(mgap, blk[0] - pmax);
      pmax = blk[1];
    }
    return mgap;
  }

 private:
  inline int findMin(const vector<int>& nums) {
    int res = INT_MAX;
    for (auto n : nums) res = min(n, res);
    return res;
  }

  inline int findMax(const vector<int>& nums) {
    int res = INT_MIN;
    for (auto n : nums) res = max(n, res);
    return res;
  }
};

struct TestCase {
  vector<int> nums;
  int res;

  bool test() { return res == Solution().maximumGap(nums); }
};

TestCase testCase1 = {
  { 3, 6, 9, 1 },
  3
};

TestCase testCase2 = {
  { 100, 3, 2, 1 },
  97
};

#define TEST(testCase) assert(testCase.test())

int main(int, char**) {
  // TEST(testCase1);
  TEST(testCase2);
  return 0;
}
