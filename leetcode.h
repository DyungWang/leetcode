// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11

#pragma once

#include <algorithm>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* createList(const std::vector<int>& vals, int s) {
  if (s == vals.size())
    return nullptr;
  auto node = new ListNode(vals[s]);
  node->next = createList(vals, s+1);
  return node;
}

ListNode* createList(const std::vector<int>& vals) {
  return createList(vals, 0);
}

void freeList(ListNode* head) {
  while (head != nullptr) {
    auto next = head->next;
    delete head;
    head = next;
  }
}

std::vector<int> listToVector(ListNode* head) {
  std::vector<int> vals;
  while (head != nullptr) {
    vals.push_back(head->val);
    head = head->next;
  }
  return vals;
}



bool equal(const std::vector<int>& arr1, const std::vector<int>& arr2) {
  if (arr1.size() != arr2.size())
    return false;
  return equal(arr1.begin(), arr1.end(), arr2.begin());
}
