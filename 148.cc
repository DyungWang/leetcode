// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/27
// @link https://leetcode.com/problems/sort-list/

#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode* tail = nullptr;
    ListNode* node = head;
    while (node != nullptr && node->val == head->val) {
      tail = node;
      node = node->next;
    }

    // split into three part.
    ListNode* phead = nullptr;
    ListNode* qhead = nullptr;
    ListNode* ptail = nullptr;
    split(tail->next, head->val, &phead, &qhead);

    // subsort of two parts.
    phead = sortList(phead);
    qhead = sortList(qhead);

    // merge three of them
    tail->next = qhead;
    ptail = findTail(phead);
    if (ptail == nullptr)
      return head;
    ptail->next = head;
    return phead;
  }

 private:
  void split(ListNode* node, int val, ListNode** phead, ListNode** qhead) {
    ListNode* ptail = *phead;
    ListNode* qtail = *qhead;
    ListNode* next = nullptr;
    while (node != nullptr) {
      next = node->next;
      node->next = nullptr;
      if (node->val <= val) {
        insertTail(node, phead, &ptail);
      } else {
        insertTail(node, qhead, &qtail);
      }
      node = next;
    }
  }

  void insertTail(ListNode* node, ListNode** head, ListNode** tail) {
    if (*head != nullptr) {
      (*tail)->next = node;
      *tail = node;
    } else {
      *head = node;
      *tail = node;
    }
  }

  ListNode* findTail(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    ListNode* tail = head;
    while (head != nullptr) {
      tail = head;
      head = head->next;
    }
    return tail;
  }
};

struct TestCase {
  vector<int> ins;
  vector<int> res;

  bool test() {
    vector<int> res;
    ListNode* head = createList(ins);
    ListNode* sort = Solution().sortList(head);
    res = listToVector(sort);
    return equal(res, this->res);
  }
};

TestCase testCase1 = {
  { 4, 2, 1, 3 },
  { 1, 2, 3, 4 }
};

#define TEST(testCase) assert(testCase.test())

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
