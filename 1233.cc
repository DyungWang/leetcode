// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/03/31

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

using namespace std;

struct Path {
  map<string, unique_ptr<Path>> subpath;
};

class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    unique_ptr<Path> root(new Path);
    for (auto& path: folder) 
      insertToPath(root.get(), path, 0);
    vector<string> result;
    pathToFolder(root.get(), "", &result);
    return result;
  }

 private:
  void insertToPath(Path* root, const string& path, int pos) {
    if (pos == path.size()) {
      root->subpath.clear();
      return;
    } 
    int spos = pos++;
    while (pos < path.size() && path[pos] != '/') 
      pos++;
    auto name = path.substr(spos, pos - spos);
    auto iter = root->subpath.find(name);
    
    Path* sub = nullptr;
    if (iter != root->subpath.end()) {
      sub = iter->second.get();
      if (sub->subpath.empty()) return; // 当前以为终点，忽略之
    } else {
      sub = new Path();
      root->subpath[name].reset(sub);
    }
    insertToPath(sub, path, pos);
  }

  void pathToFolder(Path* path, const string& parent, vector<string>* folder) {
    if (path == nullptr || path->subpath.empty()) {
      folder->push_back(parent);
      return;
    }
    for (auto& kv: path->subpath) {
      auto sub = parent + kv.first;
      auto next = kv.second.get();
      pathToFolder(next, sub, folder);
    }
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


