// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/04

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    auto tree = buildTree(manager);
    return backVist(tree, informTime, headID);
  }
 
 private:
  vector<vector<int>> buildTree(const vector<int>& manager) {
    vector<vector<int>> tree(manager.size());
    for (int i = 0; i < (int)manager.size(); ++i) {
      if (manager[i] == -1) 
        continue;
      tree[manager[i]].push_back(i);
    }
    return tree;
  }

  int backVist(const vector<vector<int>>& tree, const vector<int>& informTime, int i) {
    int time = 0;
    for (auto j : tree.at(i))
      time = max(time, backVist(tree, informTime, j));
    return time + informTime[i];
  }
};

struct TestCase {
  int n;
  int headID;
  vector<int> manager;
  vector<int> informTime;
  int result;
};

bool Test(TestCase& testCase) {
  return Solution().numOfMinutes(
      testCase.n, 
      testCase.headID, 
      testCase.manager, 
      testCase.informTime) == testCase.result;
}

TestCase case1 = {  
  4,
  2,
  { 3, 3, -1, 2 },
  { 0, 0, 162, 914 },
  1076
};

TestCase case2 = {
  7,
  6,
  { 1, 2, 3, 4, 5, 6, -1},
  { 0, 6, 5, 4, 3, 2, 1},
  21
};

int main(int, char**) {
  assert(Test(case1));
  assert(Test(case2));
  return 0;
}
