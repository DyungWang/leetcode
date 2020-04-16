// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/15
// @link https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tail = nullptr;    
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* kHead = cur;
      ListNode* kTail = cur;
      int cnt = k;
      while (--cnt >= 0 && cur != nullptr) {
        kTail = cur;
        cur = cur->next;
      }
      kTail->next = nullptr;
      if (cnt < 0) 
        reverseList(&kHead, &kTail);
      if (tail == nullptr) {
        head = kHead;
        tail = kTail;
      } else {
        tail->next = kHead;
        tail = kTail;
      }
    }
    return head;
  }

 private:
  inline void reverseList(ListNode** head, ListNode** tail) {
    ListNode* cur = *head;
    ListNode* pre = nullptr;
    ListNode* next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    swap(*head, *tail);
  }
};

struct TestCase {
  int k;
  vector<int> input;
  vector<int> output;
};

bool test(TestCase& testCase) {
  vector<int> oVector;
  ListNode* iList = createList(testCase.input);
  ListNode* oList = Solution().reverseKGroup(iList, testCase.k);
  oVector = listToVector(oList);
  freeList(oList);
  return equal(oVector, testCase.output);
}

#define TEST(testCase) assert(test(testCase));

TestCase testCase1 = {
  2,
  { 1, 2, 3, 4, 5 },
  { 2, 1, 4, 3, 5 }
};

TestCase testCase2 = {
  3,
  { 1, 2, 3, 4, 5 },
  { 3, 2, 1, 4, 5 }
};

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}

