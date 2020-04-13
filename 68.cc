// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/12
// @link https://leetcode.com/problems/text-justification/

#include <iostream>
#include <vector>
#include <string>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    vector<string> line;
    int len = 0;
    for (int i = 0; i < words.size(); ++i) {
      int minWidth = len + words[i].size() + line.size();
      if (minWidth <= maxWidth) {
        len += words[i].size();
        line.push_back(words[i]);
        continue;
      }
      result.emplace_back(package(line, len, maxWidth));
      line = { words[i] };
      len = words[i].size();
    }
    if (!line.empty()) result.emplace_back(packageLast(line, len, maxWidth));
    return result;
  }
 
 private:
  string package(vector<string>& words, int len, int maxWidth) {
    if (words.size() == 1) 
      return words[0] + string(maxWidth-len, ' ');
    int dis = (maxWidth - len) / (words.size() - 1);
    int cnt = (maxWidth - len) % (words.size() - 1);
    string line;
    for (int i = 0; i < cnt && i < words.size()-1; ++i)
      line += words[i] + string(dis+1, ' ');
    for (int i = cnt; i < words.size()-1; ++i)
      line += words[i] + string(dis, ' ');
    line += words.back();
    return line;
  }

  string packageLast(vector<string>& words, int len, int maxWidth) {
    string line;
    for (auto& word : words) line += word + " ";
    if (line.size() > maxWidth)
      line.pop_back();
    while (line.size() < maxWidth)
      line.push_back(' ');
    return line;
  }
};

struct TestCase {
  int maxWidth;
  vector<string> words;
  vector<string> result;
};

TestCase testCase1 = {
  16,
  {"This", "is", "an", "example", "of", "text", "justification."},
  {
    "This    is    an",
    "example  of text",
    "justification.  "
  }
};

TestCase testCase2 = {
  16,
  {"What", "must", "be", "acknowledgment", "shall", "be"},
  {
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
  }
};

bool test(TestCase& testCase) {
  auto result = Solution().fullJustify(testCase.words, testCase.maxWidth);
  return equal(testCase.result, result);
}

#define TEST(testCase) assert(test(testCase));

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}

