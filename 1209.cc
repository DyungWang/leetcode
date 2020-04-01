#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string removeDuplicates(string str, int k) {
    std::string res;
    if (str.empty()) 
      return res;
    size_t i = 0, j = 0;
    while (j < str.size()) {
      if (str[j] != str[i]) {
        res.insert(res.end(), str.begin()+i, str.begin()+j);
        i = j;
      }
      ++j;
      if (j-i == k) i = j;
    }
    if (i != j) res.insert(res.end(), str.begin()+i, str.begin()+j);
    if (res == str) 
      return res;
    return removeDuplicates(res, k);
  }
};

struct TestCase {
  int k;
  string test;
  string result;
};

TestCase case1 = {
  2,
  "abcd",
  "abcd"
};

TestCase case2 = {
  3,
  "deeedbbcccbdaa",
  "aa"
};

TestCase case3 = {
  2,
  "pbbcggttciiippooaais",
  "ps"
};

int main(int, char**) {
  Solution solution;
  assert(case1.result == solution.removeDuplicates(case1.test, case1.k));
  assert(case2.result == solution.removeDuplicates(case2.test, case2.k));
  assert(case3.result == solution.removeDuplicates(case3.test, case3.k));
  return 0;
}


