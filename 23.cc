// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/15
// @link https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>
#include <queue>
#include <iostream>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* lhs, ListNode* rhs) { 
      return lhs->val > rhs->val; 
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> que(cmp);
    
    ListNode head(0);
    ListNode* cur = &head;
    for (auto node : lists) if (node != nullptr)
      que.push(node);
    while (!que.empty()) {
      auto node = que.top(); que.pop();
      cur->next = node;
      cur = cur->next;
      if (node->next != nullptr) que.push(node->next);
    }
    return head.next;
  }
};

struct TestCase {
  vector<vector<int>> input;
  vector<int> output;
};

bool test(TestCase& testCase) {
  vector<int> oVector;
  vector<ListNode*> lists;
  lists.reserve(testCase.input.size());
  for (auto& vec : testCase.input)
    lists.push_back(createList(vec));
  ListNode* oList = Solution().mergeKLists(lists);
  oVector = listToVector(oList);
  freeList(oList);
  return equal(oVector, testCase.output);
}

#define TEST(testCase) assert(test(testCase));

TestCase testCase1 = {
  {
    { 1, 4, 5 },
    { 1, 3, 4 },
    { 2, 6 }
  },
  { 1, 1, 2, 3, 4, 4, 5, 6 }
};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
