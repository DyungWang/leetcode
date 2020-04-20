// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/19
// @link https://leetcode.com/problems/word-ladder-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> nextMap;
    vector<vector<string>> paths;
    vector<string> path;
    int minLength = findMinLength(beginWord, endWord, wordList, &nextMap);
    if (minLength != 0) {
      path.reserve(minLength);
      path.push_back(beginWord);
      findMinPaths(minLength, endWord, path, nextMap, &paths);
    }
    return paths;
  }
 
 private:
  inline void findNext(set<string>& words, string& word, vector<string>* nexts) {
    for (size_t i = 0; i < word.size(); ++i) {
      char c = word[i];
      for (char n = 'a'; n <= 'z'; ++n) {
        word[i] = n;
        if (words.count(word) != 0) {
          nexts->push_back(word);
        }
      }
      word[i] = c;
    }
  }

  inline int findMinLength(
      string& beginWord, string& endWord, vector<string>& wordList, 
      unordered_map<string, vector<string>>* nextMap) {
    set<string> words(wordList.begin(), wordList.end());
    queue<string> que; que.push(beginWord);
    int ret = 1;
    while (!que.empty()) {
      int len = que.size();
      for (int i = 0; i < len; ++i) {
        auto word = que.front(); que.pop();
        if (word == endWord)
          return ret;
        auto& next = (*nextMap)[word];
        words.erase(word);
        findNext(words, word, &next);
        for (auto& n : next) que.push(n);
      }
      ret++;
    }
    return 0;
  }

  inline void findMinPaths(
      int minLength,
      string& endWord, 
      vector<string>& path,
      unordered_map<string, vector<string>>& nextMap,
      vector<vector<string>>* paths) {
    if (minLength == path.size()) {
      if (path.back() == endWord)
        paths->push_back(path);
      return;
    }
    for (auto& next: nextMap[path.back()]) {
      path.push_back(next);
      findMinPaths(minLength, endWord, path, nextMap, paths);
      path.pop_back();
    }
  }
};

struct TestCase {
  string startWord;
  string endWord;
  vector<string> wordList;
  vector<vector<string>> paths;

  bool test() {
    vector<vector<string>> paths;
    paths = Solution().findLadders(startWord, endWord, wordList);
    return equal(paths, this->paths);
  }
};

TestCase testCase1 = {
  "hit",
  "cog",
  { "hot", "dot", "dog", "lot", "log", "cog" },
  {
    { "hit", "hot", "dot", "dog", "cog" },
    { "hit", "hot", "lot", "log", "cog" }
  }
};

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

