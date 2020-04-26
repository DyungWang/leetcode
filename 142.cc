// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/26
// @link https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
    }
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    while (head != fast) {
      head = head->next;
      fast = fast->next;
    }
    return head;
  }
};

struct TestCase {
  vector<int> list;
  int pos;

  bool test() {
    ListNode* head = createList(list);
    ListNode* node = makeCycle(head, pos);
    ListNode* begin = Solution().detectCycle(head);
    return node == begin;
  }

  ListNode* makeCycle(ListNode* head, int cnt) {
    if (cnt == -1) return nullptr;
    ListNode* tail = head; while (tail->next != nullptr) tail = tail->next;
    ListNode* node = head; while (cnt-- > 0) node = node->next;
    tail->next = node;
    return node;
  }
};

TestCase testCase1 = {
  { 3, 2, 0, -4 },
  1
};

#define TEST(testCase) assert(testCase.test())

int main(int, char**) {
  TEST(testCase1);
  return 0;
}

