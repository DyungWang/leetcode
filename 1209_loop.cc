#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string removeDuplicates(string str, int k) {
    vector<size_t> stk;
    vector<size_t> cnt;
    for (size_t i = 0; i < str.size(); ++i) {
      if (stk.empty() || str[stk.back()] != str[i]) {
        stk.push_back(i);
        cnt.push_back(1);
        continue;
      }
      stk.push_back(i);
      cnt.push_back(cnt.back()+1);
      if (cnt.back() < k)
        continue;
      for (int j = 0; j < k; ++j) {
        stk.pop_back();
        cnt.pop_back();
      }
    }

    std::string res;
    for (auto i: stk) res.push_back(str[i]);
    return res;
  }
};

struct TestCase {
  int k;
  string test;
  string result;
};

TestCase case1 = { 2, "abcd", "abcd" };
TestCase case2 = { 3, "deeedbbcccbdaa", "aa" };
TestCase case3 = { 2, "pbbcggttciiippooaais", "ps" };

int main(int, char**) {
  Solution solution;
  assert(case1.result == solution.removeDuplicates(case1.test, case1.k));
  assert(case2.result == solution.removeDuplicates(case2.test, case2.k));
  assert(case3.result == solution.removeDuplicates(case3.test, case3.k));
  return 0;
}


