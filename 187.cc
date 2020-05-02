// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/02
// @link https://leetcode.com/problems/repeated-dna-sequences/

#include <unordered_map>
#include <string>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> occured;
    vector<string> repeated;
    int mask = (1 << 20) - 1;
    int v = 0;
    for (int i = 0; i < 10; ++i)
      v = (v << 2) | charToInt(s[i]);
    occured[v] = 1;
    for (int i = 10; i < (int)s.size(); ++i) {
      v = ((v << 2) | charToInt(s[i])) & mask;
      if (++occured[v] == 2)
        repeated.emplace_back(s.substr(i-9, 10));
    }
    return repeated;
  }
 
 private:
  inline int charToInt(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;
  } 
};

struct TestCase {
  string s;
  vector<string> r;

  bool test() { 
    // vector<string> r(this->r.begin(), this->r.end());
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

