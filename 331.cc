// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/05

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValidSerialization(string preorder) {
    if (preorder.empty())
      return true;
    
    vector<int> stk; 
    int pos = 0;
    while (pos < preorder.size()) {
      if (!isNull(preorder, pos)) {
        stk.push_back(2);
        continue;
      }
      while (!stk.empty() && stk.back() == 1)
        stk.pop_back();
      if (stk.empty()) 
        break;
      --stk.back();
    }
    return stk.empty() && pos == preorder.size();
  }
 
 private:
  bool isNull(const string& preorder, int& p) {
    auto res = preorder[p] == '#';
    while (p < preorder.size() && preorder[p] != ',')
      ++p;
    if (p < preorder.size())
      ++p;
    return res;
  }
};

struct TestCase {
  string preorder;
  bool result;
};

TestCase testCase1 = { "9,3,4,#,#,1,#,#,2,#,6,#,#", true };
TestCase testCase2 = { "1,#", false };
TestCase testCase3 = { "9,#,#,1", false };
TestCase testCase4 = { "9,#,92,#,#", true };
TestCase testCase5 = { "#", true };

#define TEST_F(testCase) \
  assert(Solution().isValidSerialization(testCase.preorder) == testCase.result);

int main(int, char**) {
  TEST_F(testCase1);
  TEST_F(testCase2);
  TEST_F(testCase3);
  TEST_F(testCase4);
  TEST_F(testCase5);
  return 0;
}
