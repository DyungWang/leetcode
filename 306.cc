// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/21
// @link https://leetcode.com/problems/additive-number/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int len = num.size();
    int64_t s1 = 0;
    int64_t s2 = 0;
    for (int i = 0; i < min(len/2, len-2); ++i) {
      if (i > 0 && num[0] == '0') 
        break;
      s1 = s1 * 10 + num[i] - '0';
      s2 = 0;
      for (int j = i+1; j < min(i+1+len/2, len-1); ++j) {
        if (j != i+1 && num[i+1] == '0') 
          break;
        s2 = s2 * 10 + num[j] - '0';
        if (dfs(num, j+1, s1, s2))
          return true;
      }
    }
    return false;
  }
 
 private:
  bool dfs(string& num, int i, int64_t s1, int64_t s2) {
    if (i == num.size())
      return true;
    int64_t n = 0;
    for (int j = i; j < num.size(); ++j) {
      if (j != i && num[i] == '0')
        break;
      n = n * 10 + num[j] - '0';
      if ((n == s1 + s2) && dfs(num, j+1, s2, n))
        return true;
      if (n > s1 + s2)
        break;
    }
    return false;
  }
};

struct TestCase {
  string num;
  bool res;
  bool test() { return res == Solution().isAdditiveNumber(num); }
};

TestCase testCase1 = {
  "112358", true
};

TestCase testCase2 = {
  "199100199", true
};

TestCase testCase3 = {
  "123", true
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  // TEST(testCase2);
  TEST(testCase3);
  return 0;
}
