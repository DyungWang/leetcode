// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/23
// @link https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> cntMap;
    for (auto n : arr) cntMap[n]++;
    
    vector<pair<int, int>> kvVec(cntMap.begin(), cntMap.end());
    sort(kvVec.begin(), kvVec.end(), 
        [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.second < rhs.second;
        });
    int i = 0;
    while (k >= 0 && i < kvVec.size())
      k -= kvVec[i++].second;
    return k >= 0 ? 0 : (kvVec.size() - i + 1);
  }
};

struct TestCase {
  vector<int> arr;
  int k;
  int r;

  bool test() { return r == Solution().findLeastNumOfUniqueInts(arr, k); }
};

TestCase testCase1 = {
  {5,5,4}, 1, 1
};

TestCase testCase2 = {
  {4,3,1,1,3,3,2}, 3, 2
};

TestCase testCase3 = {
  {1}, 1, 0
};

TestCase testCase4 = {
  {1, 2}, 1, 1
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}

