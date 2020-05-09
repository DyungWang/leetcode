// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/09
// @link https://leetcode.com/problems/word-search-ii/

#include <vector>
#include <string>
#include <iostream>
#include "leetcode.h"

using namespace std;

struct TrieNode {
  bool end;
  vector<TrieNode*> nexts;

  TrieNode() : end(false), nexts(26, nullptr) {}
  ~TrieNode() { for (auto n : nexts) if (n != nullptr) delete n; }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = buildTrie(words);
    vector<string> result;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        string word;
        dfs(board, root, i, j, word, result);
      }
    }
    return result;
  }
 
 private:
  TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode;
    for (auto word : words)
      addWord(root, word);
    return root;
  }

  void addWord(TrieNode* root, string& word) {
    for (auto c : word) {
      auto& n = root->nexts[c - 'a'];
      if (n == nullptr) 
        n = new TrieNode;
      root = n;
    }
    root->end = true;
  }

  void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j, string& word,  vector<string>& result) {
    if (node == nullptr) return;
    if (node->end) {
      node->end = false; // to avoid dupilcate add.
      result.push_back(word);
    }
    if (i < 0 || i >= board.size()) return;
    if (j < 0 || j >= board[i].size()) return;
    if (board[i][j] == '#') return;
    char c = board[i][j]; board[i][j] = '#';
    auto n = node->nexts[c-'a'];
    word.push_back(c);
    dfs(board, n, i+1, j, word, result);
    dfs(board, n, i-1, j, word, result);
    dfs(board, n, i, j+1, word, result);
    dfs(board, n, i, j-1, word, result);
    word.pop_back();
    board[i][j] = c;
  }
};


