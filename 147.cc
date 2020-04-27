// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/27
// @link https://leetcode.com/problems/insertion-sort-list/

#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* rhead = nullptr;
    ListNode* next = nullptr;
    while (head != nullptr) {
      next = head->next;
      insertNode(&rhead, head);
      head = next;
    }
    return rhead;
  }

 private:
  void insertNode(ListNode** head, ListNode* node) {
    node->next = nullptr;
    ListNode* pre = nullptr;
    ListNode* cur = *head;
    while (cur != nullptr && cur->val < node->val) {
      pre = cur;
      cur = cur->next;
    }
    if (pre == nullptr) {
      node->next = *head;
      *head = node;
    } else {
      pre->next = node;
      node->next = cur;
    }
  }
};

struct TestCase  {
  vector<int> ins;
  vector<int> res;

  bool test() {
    vector<int> res;
    ListNode* head = createList(ins);
    ListNode* sort = Solution().insertionSortList(head);
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
