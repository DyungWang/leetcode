// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/02
// @link https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  double getProbability(vector<int>& balls) {
    vector<int> lbs(balls.size(), 0);
    vector<int> rbs(balls.size(), 0);
    int hsum = sum(balls) / 2;
    return dfs(balls, lbs, rbs, 0, 0, hsum, 0) / perm(balls);
  }
 
 private:
  double perm(vector<int>& balls) {
    double ans = 1, pos = 1;
    for (auto n : balls) for (int i = 0; i < n; ++i) {
      ans *= pos / (i + 1);
      pos += 1;
    }
    return ans;
  }

  int sum(vector<int>& balls) {
    int ans = 0;
    for (auto n : balls) ans += n;
    return ans;
  }

  int distinct(vector<int>& balls) {
    int ans = 0;
    for (auto n : balls) ans += n > 0;
    return ans;
  }

  double dfs(vector<int>& balls, vector<int>& lbs, vector<int>& rbs,
      int lsum, int rsum, int hsum, int idx) {
    if (lsum > hsum || rsum > hsum) 
      return 0;
    if (idx >= balls.size()) {
      if (distinct(lbs) != distinct(rbs))
        return 0;
      return perm(lbs) * perm(rbs);
    }
    double ans = 0;
    for (int i = 0; i <= balls[idx]; ++i) {
      lbs[idx] = i;
      rbs[idx] = balls[idx] - i;
      ans += dfs(balls, lbs, rbs, lsum+lbs[idx], rsum+rbs[idx], hsum, idx+1);
    }
    return ans;
  } 
};


struct TestCase {
  vector<int> balls;
  double res;

  bool test() {
    double ans = Solution().getProbability(balls);
    return abs(res-ans) <= 1e-5;
  }
};

TestCase testCase1 = {
  {2,1,1}, 0.66667
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
