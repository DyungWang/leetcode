// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/05
// @link https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <vector>

using namespace std;

class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> omap(n);
    vector<vector<int>> imap(n);
    for (auto& ps : connections) {
      omap[ps[0]].push_back(ps[1]);
      imap[ps[1]].push_back(ps[0]);
    }

    // bfs
    int ans = 0;
    vector<int> visit(n, 0);
    vector<int> curpt({0});
    while (!curpt.empty()) {
      vector<int> nxtpt;
      for (auto cp : curpt) {
        if (visit[cp]) continue;
        visit[cp] = 1;
        for (auto np: imap[cp]) if (!visit[np])
          nxtpt.push_back(np);
        for (auto np: omap[cp]) if (!visit[np]) {
          nxtpt.push_back(np);
          ans += 1;
        }
      }
      swap(curpt, nxtpt);
    }
    return ans;
  }
};

struct TestCase {
  vector<vector<int>> connections;
  int n;
  int r;

  bool test() { return r == Solution().minReorder(n, connections); }
};

TestCase testCase1 = {
  {{0,1},{1,3},{2,3},{4,0},{4,5}}, 6, 3
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
