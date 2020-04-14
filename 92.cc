// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/14
// @link https://leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* revHead = nullptr;
    ListNode* revTail = nullptr;
    ListNode* preTail = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    int cnt = 1;
    while (cnt < m && cur != nullptr) {
      preTail = cur;
      cur = cur->next;
      cnt = cnt + 1;
    }
    while (cnt <= n && cur != nullptr) {
      next = cur->next;
      insertHead(&revHead, &revTail, cur);
      cur = next;
      cnt = cnt + 1;
    }
    revTail->next = cur;
    if (preTail != nullptr) {
      preTail->next = revHead;
      return head;
    }
    return revHead;
  }

 private:
  inline void insertHead(ListNode** head, ListNode** tail, ListNode* node) {
    if (*head == nullptr) {
      *head = node;
      *tail = node;
    } else {
      node->next = *head;
      *head = node;
    }
  }
};

struct TestCase {
  int m;
  int n;
  vector<int> input;
  vector<int> output;
};

bool Test(TestCase& testCase) {
  vector<int> oVector;
  ListNode* iList = createList(testCase.input);
  ListNode* oList = Solution().reverseBetween(iList, testCase.m, testCase.n);
  oVector = listToVector(oList);
  freeList(oList);
  return equal(oVector, testCase.output);
}

#define TEST(testCase) assert(Test(testCase));

TestCase testCase1 = {
  2,
  4,
  { 1, 2, 3, 4, 5 },
  { 1, 4, 3, 2, 5 }
};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
