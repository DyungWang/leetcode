// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/18
// @link https://leetcode.com/problems/word-ladder/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (beginWord == endWord) 
      return 0;
    if (distance(beginWord, endWord) == 1)
      return 2;
    vector<vector<int>> map(wordList.size());
    set<int> start, end, visit;
    toNextMap(wordList, &map);
    findStart(wordList, beginWord, &start);
    findEnd(wordList, endWord, &end);
    int ret = bfsVisit(map, start, end, visit);
    return ret == 0 ? 0 : ret + 1;
  }
 
 private:
  inline int distance(const string& lhs, const string& rhs) {
    int dis = 0;
    for (size_t i = 0; i < lhs.size(); ++i)
      dis += lhs[i] != rhs[i];
    return dis;
  }

  inline void toNextMap(const vector<string>& list, vector<vector<int>>* next) {
    for (size_t i = 0; i < list.size(); ++i) for (size_t j = i+1; j < list.size(); ++j) {
      if (distance(list[i], list[j]) == 1) {
        (*next)[i].push_back(j);
        (*next)[j].push_back(i);
      }
    }
  }
  
  inline void findStart(const vector<string>& list, const string& str, set<int>* points) {
    for (size_t i = 0; i < list.size(); ++i) if (distance(list[i], str) == 1) {
      points->insert(i);
    }
  }

  inline void findEnd(const vector<string>& list, const string& str, set<int>* points) {
    for (size_t i = 0; i < list.size(); ++i) if (list[i] == str) {
      points->insert(i);
    }
  }

  inline int bfsVisit(const vector<vector<int>>& map, const set<int>& start, 
      const set<int>& end, set<int>& visit) {
    if (start.empty() || end.empty()) 
      return 0;
    set<int> next;
    for (auto s : start) {
      if (end.count(s) > 0) return 1;
      for (auto n : map[s]) if (visit.count(n) == 0) 
        next.insert(n);
      visit.insert(s);
    }
    int ret = bfsVisit(map, next, end, visit);
    return ret == 0 ? 0 : ret+1;
  }
};

struct TestCase {
  string beginWrod;
  string endWrod;
  vector<string> wordList;
  int result;
  
  bool test() { return result == Solution().ladderLength(beginWrod, endWrod, wordList); }
};

#define TEST(testCase) assert(testCase.test());

TestCase testCase1 = {
  "hit",
  "cog",
  { "hot", "dot", "dog", "lot", "log", "cog" },
  5
};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
