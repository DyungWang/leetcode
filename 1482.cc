// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/25
// @link https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < (m * k)) 
      return -1;
    int r = 0; for (auto d : bloomDay) r = max(r, d);
    int l = 0;
    while (l < r) {
      int t = (l + r) / 2;
      if (isValid(bloomDay, m, k, t))
        r = t;
      else {
        l = t + 1;
      }
    }
    return r;
  }

 private:
  bool isValid(vector<int>& bloomDay, int m, int k, int t) {
    int w = 0;
    for (auto d: bloomDay) {
      if (d > t)
        w = 0;
      else if (++w >= k) {
        w = 0;
        if (--m <= 0) return true;
      }
    }
    return false;
  }
};

struct TestCase {
  vector<int> bloomDay;
  int m;
  int k;
  int r;

  bool test() { return r == Solution().minDays(bloomDay, m, k); }
};

TestCase testCase1 = {
  {1,10,3,10,2}, 3, 1, 3
};

TestCase testCase2 = {
  {1,10,3,10,2}, 3, 2, -1
};

TestCase testCase3 = {
  {7,7,7,7,12,7,7}, 2, 3, 12
};

TestCase testCase4 = {
  {79,30,15,94,80,52,14,4,81,62,40,47,44,98,73,63,36,1,66,83,66,36,35,64,45,21,76,4,79,36,57,20,86,15,19},
  35, 1, 98
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}

