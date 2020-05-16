// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/16
// @link https://leetcode.com/problems/h-index-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int m = n;
    for (int i = 0; i < n; ++i, --m)
      if (citations[i] >= m)
        return m;
    return 0;
  }
};

struct TestCase {
  vector<int> citations;
  int hindex;
  bool test() { return hindex == Solution().hIndex(citations); }
};

TestCase testCase1 = {
  {0,1,3,5,6}, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}

