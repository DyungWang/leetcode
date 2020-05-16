// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/16
// @link https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    vector<string> res;
    if (num / kBillion != 0) {
      res.push_back(numberToWordsInThounsand(num/kBillion));
      res.push_back("Billion");
      num %= kBillion;
    }
    if (num / kMillion != 0) {
      res.push_back(numberToWordsInThounsand(num/kMillion));
      res.push_back("Million");
      num %= kMillion;
    }
    if (num / kThousand != 0) {
      res.push_back(numberToWordsInThounsand(num/kThousand));
      res.push_back("Thousand");
      num %= kThousand;
    }
    if (num != 0) {
      res.push_back(numberToWordsInThounsand(num));
    }
    return join(res);
  }
 
 private:
  string numberToWordsInThounsand(int num) {
    vector<string> res;
    if (num/100 > 0) {
      res.push_back(tt[num/100]);
      res.push_back("Hundred");
    }
    num %= 100;
    if (num / 10 == 0) {
      if (num%10 != 0) res.push_back(tt[num%10]);
    } else if (num / 10 == 1) {
      res.push_back(te[num%10]);
    } else {
      res.push_back(rr[num/10]);
      if (num%10 != 0) res.push_back(tt[num%10]);
    }
    return join(res);
  }

  string join(vector<string>& str) {
    if (str.empty()) return "";
    auto res = str[0];
    for (int32_t i = 1; i < str.size(); ++i) 
      res += " " + str[i];
    return res;
  }
 
 private:
  static vector<string> th;
  static vector<string> te;
  static vector<string> rr;
  static vector<string> tt;

  static int kBillion;
  static int kMillion;
  static int kThousand;
};

vector<string> Solution::te = { 
  "Ten",      "Eleven",    "Twelve", 
  "Thirteen", "Fourteen",  "Fifteen", 
  "Sixteen",  "Seventeen", "Eighteen", 
  "Nineteen" 
};
vector<string> Solution::rr = { 
  "",         "",          "Twenty", 
  "Thirty",   "Forty",     "Fifty", 
  "Sixty",    "Seventy",   "Eighty",
  "Ninety" 
};
vector<string> Solution::tt = { 
  "Zero",     "One",       "Two", 
  "Three",    "Four",      "Five", 
  "Six",      "Seven",     "Eight", 
  "Nine" 
};

int Solution::kThousand = 1000;
int Solution::kMillion =  1000 * 1000;
int Solution::kBillion =  1000 * 1000 * 1000;

struct TestCase {
  int32_t num;
  string res;
  bool test() { return res == Solution().numberToWords(num); }
};

TestCase testCase1 = {
  123,
  "One Hundred Twenty Three"
};

TestCase testCase2 = {
  100,
  "One Hundred"
};

TestCase testCase3 = {
  101,
  "One Hundred One"
};

TestCase testCase4 = {
  1234567,
  "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
};

TestCase testCase5 = {
  1234567891,
  "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}

