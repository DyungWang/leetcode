// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/02
// @link https://leetcode.com/problems/repeated-dna-sequences/

#include <unordered_set>
#include <string>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> occured;
    unordered_set<string> repeated;
    for (int i = 0; i <= (int)s.size() - 10; ++i) {
      auto sub = s.substr(i, 10);
      if (occured.count(sub) != 0)
        repeated.emplace(sub);
      else {
        occured.emplace(sub);
      }
    }
    return { repeated.begin(), repeated.end() };
  }
};

struct TestCase {
  string s;
  unordered_set<string> r;

  bool test() { 
    vector<string> r(this->r.begin(), this->r.end());
    return equal(r, Solution().findRepeatedDnaSequences(s)); 
  }
};

TestCase testCase1 = {
  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
  { "AAAAACCCCC", "CCCCCAAAAA" }
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  #undef TEST
  return 0;
}

