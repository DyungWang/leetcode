// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/26
// @link https://leetcode.com/problems/reorder-list/

#include "leetcode.h"

using namespace std;

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) 
      return;
    ListNode* ptail = findMid(head);
    ListNode* qhead = reverseList(ptail->next);
    ptail->next = nullptr;
    mergeList(head, qhead);
  }

 private:
  ListNode* findMid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* tail = nullptr;
    while (fast != nullptr && fast->next != nullptr) {
      tail = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    return tail;
  } 

  ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* nxt = nullptr;
    while (cur != nullptr) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }

  ListNode* mergeList(ListNode* phead, ListNode* qhead) {
    ListNode* pcur = phead;
    ListNode* pnxt = nullptr;
    ListNode* qcur = qhead;
    ListNode* qnxt = nullptr;
    while (pcur != nullptr && qcur != nullptr) {
      pnxt = pcur->next;
      qnxt = qcur->next;
      pcur->next = qcur;
      if (pnxt != nullptr) 
        qcur->next = pnxt;
      pcur = pnxt;
      qcur = qnxt;
    }
    return phead;
  }
};

struct TestCase {
  vector<int> inputs;
  vector<int> outputs;

  bool test() {
    vector<int> outs;
    ListNode* list = createList(inputs);
    Solution().reorderList(list);
    outs = listToVector(list);
    return equal(outs, outputs);
  }
};

#define TEST(testCase) assert(testCase.test())

TestCase testCase1 = {
  { 1, 2, 3, 4 },
  { 1, 4, 2, 3 }
};

TestCase testCase2 = {
  { 1, 2, 3, 4, 5 },
  { 1, 5, 2, 4, 3 }
};

int main(int, char**) {
  TEST(testCase1);
  TEST(testCase2);
  return 0;
}
