// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/18
// @link https://leetcode.com/problems/word-ladder/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    deque<string> todo;
    todo.push_back(beginWord);
    int ret = 1;
    while (!todo.empty()) {
      int len = todo.size();
      for (int i = 0; i < len; ++i) {
        auto cur = todo.front(); 
        todo.pop_front();
        if (cur == endWord) 
          return ret;
        for (size_t j = 0; j < cur.size(); ++j) {
          char c = cur[j];
          for (int k = 0; k < 26; ++k) {
            cur[j] = 'a' + k;
            auto iter = words.find(cur);
            if (iter != words.end()) {
              todo.emplace_back(*iter);
              words.erase(iter);
            }
          }
          cur[j] = c;
        }
      }
      ret++;
    }
    return 0;
  }
 
 private: 
  inline bool distanceIsOne(const string& lhs, const string& rhs) {
    int dis = 0;
    for (size_t i = 0; i < lhs.size(); ++i) {
      dis += lhs[i] != rhs[i];
      if (dis > 1) return false;
    }
    return dis == 1;
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
