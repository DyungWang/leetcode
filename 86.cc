// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/14
// @link https://leetcode.com/problems/partition-list/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* lessHead = nullptr;
    ListNode* lessTail = nullptr;
    ListNode* greaterHead = nullptr;
    ListNode* greaterTail = nullptr;
    
    ListNode* cur = head;
    ListNode* next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      if (cur->val < x) {
        insertTail(&lessHead, &lessTail, cur);
      } else {
        insertTail(&greaterHead, &greaterTail, cur);
      }
      cur = next;
    }
    if (lessTail != nullptr) {
      lessTail->next = greaterHead;
      return lessHead;
    }
    return greaterHead;
  }

  void insertTail(ListNode** head, ListNode** tail, ListNode* node) {
    if (*head == nullptr) {
      *head = node;
      *tail = node;
    } else {
      (*tail)->next = node;
      *tail = node;
    }
    (*tail)->next = nullptr;
  }
};

struct TestCase {
  int x;
  vector<int> input;
  vector<int> output;
};

bool Test(TestCase& testCase) {
  vector<int> oVector;
  ListNode* iList = createList(testCase.input);
  ListNode* oList = Solution().partition(iList, testCase.x);
  oVector = listToVector(oList);
  freeList(oList);
  return equal(oVector, testCase.output);
}

#define TEST(testCase) assert(Test(testCase));

TestCase testCase1 = {
  3,
  { 1, 4, 3, 2, 5, 2 },
  { 1, 2, 2, 4, 3, 5 }
};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

