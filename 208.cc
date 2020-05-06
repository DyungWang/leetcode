// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/06
// @link https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {}
  
  /** Inserts a word into the trie. */
  void insert(string word) {
    Node* node = &root_;
    for (auto c : word) {
      if (node->nexts[c-'a'] == nullptr)
        node->nexts[c-'a'] = new Node;
      node = node->nexts[c-'a'];
    }
    node->end = true;
  }
  
  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node* node = findTail(word);
    return node != nullptr && node->end;
  }
  
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    return findTail(prefix) != nullptr;
  }
 
 private:
  struct Node {
    bool end = false;
    vector<Node*> nexts;

    Node(): nexts(26, nullptr) { }
  };
 
  Node* findTail(string word) {
    Node* node = &root_;
    for (auto c : word) {
      if (node->nexts[c-'a'] == nullptr) 
        return nullptr;
      node = node->nexts[c-'a'];
    }
    return node;
  }

 private:
  Node root_;
};

void testCase1() {
  Trie* trie = new Trie;
  trie->insert("hello");
  trie->insert("world");
  assert(true == trie->search("hello"));
  assert(false == trie->search("hell"));
  assert(true == trie->startsWith("hell"));
}

int main(int, char**) {
  testCase1();
  return 0;
}




