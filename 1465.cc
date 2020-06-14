// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/14
// @link https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
    int64_t hGap = maxGap(h, hCuts);
    int64_t wGap = maxGap(w, vCuts);
    return (hGap * wGap) % mod;
  }
 
 private:
  inline int maxGap(int w, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    int p = 0, r = 0;
    for (auto c : cuts) {
      r = max(r, c - p);
      p = c;
    }
    return max(r, w-p);
  }

  static int64_t mod;
};

int64_t Solution::mod = pow(10, 9) + 7;


struct TestCase {
  int h;
  int w;
  vector<int> hCuts;
  vector<int> wCuts;
  int r;

  bool test() { return r == Solution().maxArea(h, w, hCuts, wCuts); }
};

TestCase testCase1 = {
  5, 4, {1,2,4}, {1, 3}, 4
};

TestCase testCase2 = {
  50, 15,
  {37,40,41,30,27,10,31},
  {2,1,9,5,4,12,6,13,11},
  51
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  TEST(testCase2);
  return 0;
}




