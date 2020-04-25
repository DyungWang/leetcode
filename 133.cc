// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/24
// @link https://leetcode.com/problems/clone-graph/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    // return bfsClone(node);
    return dfsClone(node);
  }
 
 private:
  Node* bfsClone(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<Node*, Node*> oldNewMap = { {node, new Node(node->val)} };
    unordered_set<Node*> visit;
    unordered_set<Node*> todos({node});
    while (!todos.empty()) {
      unordered_set<Node*> nexts;
      for (auto oldNode : todos) {
        auto newNode = oldNewMap[oldNode];
        for (auto oldNext : oldNode->neighbors) {
          if (nexts.count(oldNext) != 0) 
            continue;
          auto iter = oldNewMap.find(oldNext);
          if (iter == oldNewMap.end()) {
            nexts.insert(oldNext);
            oldNewMap[oldNext] = new Node(oldNext->val);
            continue;
          }
          newNode->neighbors.push_back(iter->second);
          if (todos.count(oldNext) == 0) 
            iter->second->neighbors.push_back(newNode);
        }
      }
      swap(todos, nexts);
    }
    return oldNewMap[node];
  }

  Node* dfsClone(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<Node*, Node*> oldNewMap;
    unordered_set<Node*> visited;
    dfsClone(node, oldNewMap, visited);
    return oldNewMap[node];
  }

  void dfsClone(Node* oldNode, unordered_map<Node*, Node*>& oldNewMap, unordered_set<Node*>& visited) {
    if (visited.count(oldNode) != 0)
      return;
    visited.insert(oldNode);
    auto newNode = new Node(oldNode->val);
    oldNewMap[oldNode] = newNode;
    for (auto oldNext : oldNode->neighbors) {
      auto iter = oldNewMap.find(oldNext);
      if (iter != oldNewMap.end()) {
        auto newNext = iter->second;
        newNode->neighbors.push_back(newNext);
        newNext->neighbors.push_back(newNode);
      }
    }
    for (auto oldNext : oldNode->neighbors) dfsClone(oldNext, oldNewMap, visited);
  }
};

Node* testCase1() {
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  node1->neighbors = { node4, node2 };
  node2->neighbors = { node1, node3 };
  node3->neighbors = { node2, node4 };
  node4->neighbors = { node3, node1 };
  return node1;
}

Node* testCase2() {
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  node1->neighbors = { node2, node3 };
  node2->neighbors = { node1, node3 };
  node3->neighbors = { node1, node2 };
  return node1;
}

int main(int, char**) {
  Solution solution;
  Node* res1 = solution.cloneGraph(testCase1());
  Node* res2 = solution.cloneGraph(testCase2());
  return 0;
}
