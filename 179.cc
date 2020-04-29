// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/29
// @link https://leetcode.com/problems/largest-number/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> strs; strs.reserve(nums.size());
    for (auto n : nums) 
      strs.push_back(to_string(n));
    sort(strs.begin(), strs.end(), [](string& qstr, string& pstr) {
      int i = 0;
      while (i < qstr.size() || i < pstr.size()) {
        if (qstr[i % qstr.size()] > pstr[i % pstr.size()])
          return true;
        if (qstr[i % qstr.size()] < pstr[i % pstr.size()])
          return false;
        i++
      }
      return false;
    });

    return merge(strs);
  }

 private:
  string merge(vector<string>& strs) {
    int len = 0;
    for (auto& s : strs) 
      len += s.size();

    string res(len, ' ');
    char* data = &res[0];
    for (auto& s : strs) {
      memcpy(data, s.data(), sizeof(char) * s.size());
      data += s.size();
    }
    return res;
  }
};

struct TestCase {
  vector<int> nums;
  string res;

  bool test() { return res == Solution().largestNumber(nums); }
};

TestCase testCase1 = {
  { 10, 2 },
  "210"
};

#define TEST(testCase) assert(testCase.test())

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
