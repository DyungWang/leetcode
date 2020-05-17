// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/17
// @link https://leetcode.com/problems/expression-add-operators/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> addOperatorsWorker(vector<int>::const_iterator I,
                                  vector<int>::const_iterator E,
                                  const int64_t target, const char lowOpr,
                                  const int64_t low, const int64_t high) {
    vector<string> results;
    int64_t n = 0;
    for (auto i = I; i < E; ++i) {
      // Prevent "00...0" and "0x..x":
      if (i != I && *I == 0)
        continue;

      n = n * 10LL + *i;
      int64_t k = (lowOpr == '+') ? (low + n * high) : (low - n * high);
      if (i == E - 1) {
        if (target == k)
          results.push_back(to_string(n));
      } else {
        // For +/-, compute the current accumulated result.
        // Reset the high-precedence operand.
        for (auto &&r : addOperatorsWorker(i + 1, E, target, '+', k, 1))
          results.push_back(to_string(n) + '+' + r);
        for (auto &&r : addOperatorsWorker(i + 1, E, target, '-', k, 1))
          results.push_back(to_string(n) + '-' + r);

        // For multiplication, just carry over low-precedence accumulated result.
        // But, compute the hig-precedence operand now.
        for (auto &&r : addOperatorsWorker(i + 1, E, target, lowOpr, low, n * high))
          results.push_back(to_string(n) + '*' + r);
      }
    }

    return results;
  }

  vector<string> addOperators(string num, int target) {
    if (num.length() == 0)
      return {};

    // Expand to a digit vector.
    vector<int> N;
    for (char c : num)
      N.push_back(c - '0');

    // "+ 0" and "* 1" for the starting condition; doesn't alter the value.
    return addOperatorsWorker(N.cbegin(), N.cend(), target, '+', 0, 1);
  }
};

struct TestCase {
  string num;
  int target;

  vector<string> res;

  bool test() { return  equal(res, Solution().addOperators(num, target)); }
};

TestCase testCase1 = {
  "123", 6, {"1+2+3", "1*2*3"}
};

TestCase testCase2 = {
  "232", 8, {"2+3*2", "2*3+2"}
};

TestCase testCase3 = {
  "105", 5, {"1*0+5", "10-5"}
};

TestCase testCase4 = {
  "2147483647", 2147483647, {"2147483647"}
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  // TEST(testCase1);
  // TEST(testCase2);
  // TEST(testCase3);
  TEST(testCase4);
  return 0;
}




