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
    priority_queue<int, vector<int>, greater<int>> 
      que(citations.begin(), citations.end()); 
    int idx = citations.size();
    while (!que.empty() && que.top() < idx) {
      que.pop();
      --idx;
    }
    return idx;
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
