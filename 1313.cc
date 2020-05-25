// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/25
// @link https://leetcode.com/problems/decompress-run-length-encoded-list/

#include <vector>
#include <string>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    int len = 0;
    for (int i = 0; i < nums.size(); i += 2)
      len += nums[i];
    vector<int> res;
    res.reserve(len);
    for (int i = 0; i < nums.size(); i += 2) {
      for (int j = 0; j < nums[i]; ++j)
        res.push_back(nums[i+1]);
    }
    return res;
  }
};

struct TestCase {
  vector<int> nums;
  vector<int> res;

  bool test() { return equal(res, Solution().decompressRLElist(nums)); }
};

TestCase testCase1 = {
  {1,2,3,4},
  {2,4,4,4}
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
