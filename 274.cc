// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/16
// @link https://leetcode.com/problems/h-index/

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> buckets(n+2, 0);
    for (auto c : citations)
      c >= n ? buckets[n]++ : buckets[c]++;
    for (int i = n; i >= 0; --i) {
      buckets[i] += buckets[i+1];
      if (buckets[i] >= i) 
        return i;
    }
    return 0;
  }
};

struct TestCase {
  vector<int> cita;
  int idx;
  bool test() { return idx == Solution().hIndex(cita); }
};

TestCase testCase1 = {
  {3,0,6,1,5}, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
