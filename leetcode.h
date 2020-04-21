// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/11

#pragma once

#include <algorithm>
#include <vector>
#include <string>

// for list ----------------------------------------------------------------------

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

// for tree ---------------------------------------------------------------------

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const std::vector<std::string>& preOrder, size_t& s) {
  if (s == preOrder.size()) 
    return nullptr;
  if (preOrder[s] == "#") 
    return nullptr;
  TreeNode* node = new TreeNode(std::stoi(preOrder[s]));
  node->left = createTree(preOrder, ++s);
  node->right = createTree(preOrder, ++s);
  return node;
}

TreeNode* createTree(const std::vector<std::string>& preOrder) {
  size_t s = 0;
  return createTree(preOrder, s);
}

void freeTree(TreeNode* root) {
  if (root == nullptr) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

void treePreOrder(TreeNode* root, std::vector<std::string>& preOrder) {
  if (root == nullptr) {
    preOrder.push_back("#");
    return;
  }
  preOrder.push_back(std::to_string(root->val));
  treePreOrder(root->left, preOrder);
  treePreOrder(root->right, preOrder);
}

// for test ---------------------------------------------------------------------
template<class T>
bool equal(const std::vector<T>& arr1, const std::vector<T>& arr2) {
  if (arr1.size() != arr2.size())
    return false;
  return equal(arr1.begin(), arr1.end(), arr2.begin());
}

bool equal(const std::vector<int>& arr1, const std::vector<int>& arr2) {
  if (arr1.size() != arr2.size())
    return false;
  return equal(arr1.begin(), arr1.end(), arr2.begin());
}

bool equal(const std::vector<std::string>& arr1, const std::vector<std::string>& arr2) {
  if (arr1.size() != arr2.size())
    return false;
  return equal(arr1.begin(), arr1.end(), arr2.begin());
}

template<class T>
bool equal(
    const std::vector<std::vector<T>>& arr1, 
    const std::vector<std::vector<T>>& arr2) {
  if (arr1.size() != arr2.size())
    return false;
  for (size_t i = 0; i < arr1.size(); ++i)
    if (!equal(arr1[i], arr2[i]))
      return false;
  return true;
}

