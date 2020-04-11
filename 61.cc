// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11
// @link https://leetcode.com/problems/rotate-list/

#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    
    int len = 0;
    ListNode* tail = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ++len;
      tail = cur;
      cur = cur->next;
    }

    k = (len - k % len) % len;
    if (k == 0) return head; // no need to rotate.

    tail->next = head;
    while (k-- > 0) {
      tail = head;
      head = head->next;
    }
    tail->next = nullptr;
    return head;
  }
};

struct TestCase {
  int k;
  vector<int> input;
  vector<int> output;
};

bool Test(TestCase testCase) {
  std::vector<int> outputVector;
  ListNode* inputList = createList(testCase.input);
  ListNode* outputList = Solution().rotateRight(inputList, testCase.k);
  outputVector = listToVector(outputList);
  freeList(outputList);
  return equal(testCase.output, outputVector);
}

#define TEST(testCase) assert(Test(testCase));

TestCase testCase1 = {
  1,
  { 1, 2, 3, 4, 5 },
  { 5, 1, 2, 3, 4 }
};

TestCase testCase2 = {
  2,
  { 1, 2, 3, 4, 5 },
  { 4, 5, 1, 2, 3 }
};

int main(int, char**) {
  assert(Test(testCase1));
  assert(Test(testCase2));
  return 0;
}
