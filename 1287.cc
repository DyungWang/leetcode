// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/10
// @link https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    // 因为递增且长度超过1/4，则元素必为 arr[len/4], arr[len/2], arr[len*3/4]中的一个
    // 只需要查找vector中这三个元素的个数即可
    int len = arr.size();
    vector<int> canditates({arr[len/4], arr[len/2], arr[len*3/4]});
    for (auto cand : canditates) if (countElement(arr, cand) * 4 > len)
      return cand;
    return -1;
  }

 private:
  int countElement(const vector<int>& arr, int n) {
    auto st = lower_bound(arr.begin(), arr.end(), n);
    auto et = upper_bound(arr.begin(), arr.end(), n);
    return distance(st, et);
  }
};

struct TestCase {
  vector<int> arr;
  int res;
};

#define TEST(testCase) \
    assert(Solution().findSpecialInteger(testCase.arr) == testCase.res);

TestCase testCase1 = {{1,2,2,6,6,6,6,7,10}, 6};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
