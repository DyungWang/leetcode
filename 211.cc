// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/08
// @link https://leetcode.com/problems/add-and-search-word-data-structure-design/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary() {}
    
  /** Adds a word into the data structure. */
  void addWord(string word) {
    Node* node = &root_;
    for (auto c : word) {
      auto& n = node->children[c - 'a'];
      if (n == nullptr)
        n = new Node;
      node = n;
    }
    node->end = true;
  }
    
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search(&root_, word, 0);
  }
 
 private:
  struct Node {
    bool end;
    vector<Node*> children;
    
    Node() : end(false), children(26, nullptr) {}
    ~Node() { for (auto n : children) if (n != nullptr) delete n; }
  };

  bool search(Node* node, const string& word, int i) {
    if (node == nullptr) return false;
    if (i == word.size()) return node->end;
    auto c = word[i];
    if (c != '.') 
      return search(node->children[c-'a'], word, i+1);
    for (auto n : node->children) if (search(n, word, i+1))
      return true;
    return false;
  }

 private:
  Node root_;
};

#define addWord(word) obj->addWord(word);
#define search(word) cout << obj->search(word) << endl;

void TestCase1() {
  WordDictionary* obj = new WordDictionary();
  addWord("bad");
  addWord("dad");
  addWord("mad");
  search("pad");
  search("bad");
  search(".ad");
  search("b..");
  delete obj;
}

int main(int, char**) {
  TestCase1();
  return 0;
}
