// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/09
// @link https://leetcode.com/problems/the-k-strongest-values-in-an-array/

#include <vector>
#include <algorithm>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int m = (n - 1) / 2;
    int l = 0, r = n - 1;
  
    vector<int> ans;
    while (--k >= 0) {
      int ld = arr[m] - arr[l];
      int rd = arr[r] - arr[m];
      if (rd >= ld) {
        ans.push_back(arr[r]);
        --r;
      } else {
        ans.push_back(arr[l]);
        ++l;
      }
    }
    return ans;
  }
};

struct TestCase {
  vector<int> arr;
  vector<int> res;
  int k;

  bool test() { return equal(res, Solution().getStrongest(arr, k)); }
};

TestCase testCase1 = {
  { 1, 2, 3, 4, 5 }, { 5, 1 }, 2
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test());
  TEST(testCase1);
  return 0;
}
