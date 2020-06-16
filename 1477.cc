// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/15
// @link https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

#include <vector>

using namespace std;

class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    vector<int> len(arr.size(), INT_MAX);
    vector<int> mlr(arr.size(), INT_MAX);
    
    int p = 0, sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
      sum += arr[i];
      while (sum > target) sum -= arr[p++];
      if (sum == target) len[p] = i-p+1;
    }

    for (int i = arr.size()-2; i >= 0; --i)
      mlr[i] = min(mlr[i+1], len[i+1]);

    int ans = INT_MAX;
    for (int i = 0; i < arr.size(); ++i) {
      if (len[i] == INT_MAX)
        continue;
      int j = i + len[i] - 1;
      if (mlr[j] == INT_MAX)
        continue;
      ans = min(len[i]+mlr[j], ans);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

struct TestCase {
  vector<int> arr;
  int target;
  int result;
  bool test() { return result == Solution().minSumOfLengths(arr, target); }
};

TestCase testCase1 = {
  {3,2,2,4,3}, 3, 2
};

TestCase testCase2 = {
  {4,3,2,6,2,3,4}, 6, -1
};

TestCase testCase3 = {
  {5,5,4,4,5}, 3, -1
};

TestCase testCase4 = {
  {3,1,1,1,5,1,2,1}, 3, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}

