// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/18
// @link https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    return sortedListToBST(head, nullptr);
  }
 
 private:
  inline ListNode* findMid(ListNode* head, ListNode* end) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != end && fast->next != end) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  inline TreeNode* sortedListToBST(ListNode* head, ListNode* end) {
    if (head == end)
      return nullptr;
    ListNode* mid = findMid(head, end);
    if (mid == end)
      return new TreeNode(head->val);
    TreeNode* node = new TreeNode(mid->val);
    node->left = sortedListToBST(head, mid);
    node->right = sortedListToBST(mid->next, end);
    return node;
  }
};

struct TestCase {
  vector<int> input;
  vector<string> output;
};

bool test(TestCase& testCase) {
  vector<string> output;
  ListNode* list = createList(testCase.input);
  TreeNode* tree = Solution().sortedListToBST(list);
  treePreOrder(tree, output);
  freeTree(tree);
  return equal(output, testCase.output);
}

#define TEST(testCase) assert(test(testCase));

TestCase testCase1 {
  { -10, -3, 0, 5, 9 },
  {  "0", "-3", "-10", "#", "#", "#", "9", "5", "#", "#", "#" }
};

int main(int, char**) {
  TEST(testCase1);
  return 0;
}
