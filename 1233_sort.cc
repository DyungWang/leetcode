#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> result = { folder[0] };
    for (auto& path: folder) {
      if (!isSubDir(result.back(), path))
        result.push_back(path);
    }
    return result;
  }
 private:
  bool isSubDir(const string& last, const string& cur) {
    if (!startWith(cur, last))
      return false;
    return cur.size() == last.size() || cur[last.size()] == '/'; 
  }

  bool startWith(const string& str, const string& head) {
    if (str.size() < head.size()) 
      return false;
    for (uint32_t i = 0; i < head.size(); ++i) {
      if (str[i] != head[i])
        return false;
    }
    return true;
  }

};

struct TestCase {
  vector<string> test;
  vector<string> result;
};

TestCase case1 = {
  { "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" },
  { "/a", "/c/d", "/c/f" }
};

TestCase case2 = {
  { "/a/b/c", "/a/b/d", "/a" },
  { "/a" }
};

TestCase case3 = {
  { "/a/b/c", "/a/b/ca", "/a/b/d" },
  { "/a/b/c", "/a/b/ca", "/a/b/d" }
};

template<class T>
bool equal(const vector<T>& slhs, const vector<T>& srhs) {
  vector<T> lhs = slhs;
  vector<T> rhs = srhs;
  sort(lhs.begin(), lhs.end());
  sort(rhs.begin(), rhs.end());
  if (lhs.size() != rhs.size())
    return false;
  for (size_t i = 0; i < lhs.size(); ++i)
    if (lhs[i] != rhs[i]) 
      return false;
  return true;
}

int main(int, char**) {
  Solution solution;
  assert(equal(case1.result, solution.removeSubfolders(case1.test)));
  assert(equal(case2.result, solution.removeSubfolders(case2.test)));
  assert(equal(case3.result, solution.removeSubfolders(case3.test)));
  return 0;
}

