// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/03/30

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> res;
    res.reserve(queries.size());
    for (auto& query: queries) 
      res.push_back(camelMatch(query, pattern));
    return res;
  }

  bool camelMatch(const std::string& query, const std::string& pattern) {
    if (query.size() < pattern.size())
      return false;
    int qi = 0, qLen = query.size();
    int pi = 0, pLen = pattern.size();
    while (qi < qLen && pi < pLen) {
      if (query[qi] == pattern[pi]) {
        qi++;
        pi++;
        continue;
      }
      if (!islower(query[qi]))
        return false;
      qi++;
    }
    if (pi < pLen) // some letter is miss
      return false;
    while (qi < qLen) if (!islower(query[qi++])) 
      return false;
    return true;
  }
};

template<class T>
bool equal(const std::vector<T>& lhs, const std::vector<T>& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (size_t i = 0; i < lhs.size(); ++i)
    if (lhs[i] != rhs[i]) 
      return false;
  return true;
}

struct TestCase {
  string pattern;
  vector<string> queries;
  vector<bool> result;
};

TestCase case1 = { 
  "FB",
  { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" },
  { true, false, true, true, false }
};

TestCase case2 = {
  "FoBa",
  { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" },
  { true, false, true, false, false }
};

TestCase case3 = {
  "FoBaT",
  { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"},
  { false, true, false, false, false }
};

int main(int, char**) {
  Solution solution;
  // for case1
  assert(equal(case1.result, solution.camelMatch(case1.queries, case1.pattern)));
  // for case2
  assert(equal(case2.result, solution.camelMatch(case2.queries, case2.pattern)));
  // for case3
  assert(equal(case3.result, solution.camelMatch(case3.queries, case3.pattern)));
  return 0;
}
