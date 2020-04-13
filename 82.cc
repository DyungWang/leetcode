// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/13
// @link https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      int cnt = 0;
      while (cur->next != nullptr && cur->val == cur->next->val) {
        cnt++;
        deleteNode(cur, cur->next, &head);
      } 
      if (cnt > 0)
        cur = deleteNode(pre, cur, &head);
      else {
        pre = cur;
        cur = cur->next;
      }
    }
    return head;
  }

 private:
  ListNode* deleteNode(ListNode* pre, ListNode* cur, ListNode** head) {
    if (pre == nullptr) {
      *head = cur->next;
      delete cur;
      return *head;
    }
    pre->next = cur->next;
    delete cur;
    return pre->next;
  }
};

struct TestCase {
  vector<int> input;
  vector<int> output;
};

bool Test(TestCase& testCase) {
  vector<int> outputVector;
  ListNode* inputList = createList(testCase.input);
  ListNode* outputList = Solution().deleteDuplicates(inputList);
  outputVector = listToVector(outputList);
  freeList(outputList);
  return equal(testCase.output, outputVector);
}

#define TEST(testCase) assert(Test(testCase));

TestCase testCase1 = {
  { 1, 2, 3, 3, 4, 4, 5 },
  { 1, 2, 5 }
};

TestCase testCase2 = {
  { 1, 1, 1, 2, 3 },
  { 2, 3 }
};

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}

