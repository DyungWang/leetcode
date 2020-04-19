// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/19
// @link https://leetcode.com/problems/word-ladder-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    vector<vector<int>> nextMap;
    vector<vector<string>> paths;
    vector<string> path;
    initNextMap(wordList, &nextMap);
    int minLength = findMinLength(endWord, wordList, nextMap);
    if (minLength == 0)
      return  {};
    path.push_back(beginWord);
    findMinPath(endWord, wordList, nextMap, wordList.size()-1, minLength, path, &paths);
    return paths;
  }
 
 private:
  inline void initNextMap(vector<string>& wordList, vector<vector<int>>* nextMap) {
    nextMap->resize(wordList.size());
    unordered_map<string, int> wordIndex;
    for (int i = 0; i < wordList.size(); ++i) 
      wordIndex[wordList[i]] = i;
    for (int i = 0; i < wordList.size(); ++i) {
      string& word = wordList[i];
      for (int j = 0; j < word.size(); ++j) {
        char c = word[j];
        for (int k = 0; k < 26; ++k) {
          word[j] = 'a' + k;
          if (word[j] == c) 
            continue;
          auto iter = wordIndex.find(word);
          if (iter != wordIndex.end()) nextMap->at(i).push_back(iter->second);
        }
        word[j] = c;
      }
    }
  }

  inline int findMinLength(
      string& endWord, 
      vector<string>& wordList, 
      vector<vector<int>>& nextMap) {
    vector<int> visited(wordList.size(), 0);
    queue<int> tovisit;
    tovisit.push(wordList.size()-1);
    int ret = 1;
    while (!tovisit.empty()) {
      int len = tovisit.size();
      for (int i = 0; i < len; ++i) {
        int c = tovisit.front(); tovisit.pop();
        if (wordList[c] == endWord)
          return ret;
        visited[c] = 1;
        for (int n : nextMap[c]) {
          if (!visited[n]) tovisit.push(n);
        }
      }
      ret++;
    }
    return 0;
  }

  inline void findMinPath(
      string& endWord, 
      vector<string>& wordList, 
      vector<vector<int>>& nextMap,
      int startPos,
      int minLenth,
      vector<string>& path,
      vector<vector<string>>* paths) {
    if (minLenth <= 1) {
      if (path.back() == endWord)
        paths->push_back(path);
      return;
    }
    for (int n : nextMap[startPos]) {
      path.push_back(wordList[n]);
      findMinPath(endWord, wordList, nextMap, n, minLenth-1, path, paths);
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

