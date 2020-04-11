// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11
// @link https://leetcode.com/problems/valid-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    auto str = trim(s);
    auto pos = 0u;
    if (!readNum(str, pos)) 
      return false;
    if (pos == str.size())
      return true;
    if (!readE(str, pos) || pos == str.size())
      return false;
    readSign(str, pos);
    return readOneNum(str, pos) && pos == str.size();
  }

 private:
  string trim(const string& str) {
    size_t spos = 0;              // pos of first non blank char
    size_t epos = str.size() - 1; // pos of last non blank char
    while (spos < str.size() && str[spos] == ' ')
      ++spos;
    while (epos >= 0 && str[epos] == ' ')
      --epos;
    return str.substr(spos, epos-spos+1);
  }

  bool readSign(const string& str, uint32_t& pos) {
    if (str[pos] == '+' || str[pos] == '-') {
      ++pos;
      return true;
    }
    return false;
  }

  bool readOneNum(const string& str, uint32_t& pos) {
    auto cnt = 0u;
    while (pos != str.size() && isdigit(str[pos])) {
      ++pos;
      ++cnt;
    }
    return cnt > 0;
  }

  bool readE(const string& str, uint32_t& pos) {
    if (pos < str.size() && str[pos] == 'e') {
      ++pos;
      return true;
    }
    return false;
  }

  bool readPoint(const string& str, uint32_t& pos) {
    if (pos < str.size() && str[pos] == '.') {
      ++pos;
      return true;
    }
    return false;
  }

  bool readNum(const string& str, uint32_t& pos) {
    readSign(str, pos);
    auto rn1 = readOneNum(str, pos);
    auto pnt = readPoint(str, pos);
    auto rn2 = readOneNum(str, pos);
    return rn1 || rn2;
  }
};

#define TEST(s, r) assert(Solution().isNumber(s) == r);

int main(int, char**) {
  TEST("0", true);
  TEST(" 0.1 ", true);
  TEST("abc", false);
  TEST("1 a", false);
  TEST("2e10", true);
  TEST(" -90e3   ", true);
  TEST(" 1e", false);
  TEST("e3", false);
  TEST(" 6e-1", true);
  TEST(" 99e2.5 ", false);
  TEST("53.5e93", true);
  TEST(" --6 ", false);
  TEST("-+3", false);
  TEST("95a54e53", false);
  return 0;
}
