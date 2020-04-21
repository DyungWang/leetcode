// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/19
// @link https://leetcode.com/problems/word-ladder-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>
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
  inline void findNext(unordered_set<string>& words, string word, vector<string>* nexts) {
    for (size_t i = 0; i < word.size(); ++i) {
      char c = word[i];
      for (char n = 'a'; n <= 'z'; ++n) {
        word[i] = n;
        if (words.count(word) != 0) nexts->push_back(word);
      }
      word[i] = c;
    }
  }

  inline int findMinLength(
      string& beginWord, string& endWord, vector<string>& wordList, 
      unordered_map<string, vector<string>>* nextMap) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    unordered_set<string> todos = { beginWord };
    unordered_set<string> nexts;
    int ret = 1;
    while (!todos.empty()) {
      if (todos.count(endWord) != 0)
        return ret;
      for (auto& word: todos) 
        words.erase(word);
      for (auto& word: todos) {
        auto& next = (*nextMap)[word];
        findNext(words, word, &next);
        nexts.insert(next.begin(), next.end());
      }
      todos.clear(); swap(todos, nexts);
      ret++;
    }
    return 0;
  }

  inline void findMinPaths(
      int minLength, string& endWord, vector<string>& path,
      unordered_map<string, vector<string>>& nextMap, vector<vector<string>>* paths) {
    if (minLength == path.size()) {
      if (path.back() == endWord)
        paths->push_back(path);
      return;
    }
    auto& nexts = nextMap[path.back()];
    for (auto& next: nexts) {
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

TestCase testCase2 = {
  "kiss",
  "tusk",
  { "miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss" },
  {
    { "kiss","diss","disk","dusk","tusk" },
    { "kiss","miss","muss","musk","tusk" }
  }
};

#define TEST(testCase) assert(testCase.test());

int main(int, char**) {
  // TEST(testCase1);
  TEST(testCase2);
  return 0;
}

