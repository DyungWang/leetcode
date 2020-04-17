// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/17
// @link https://leetcode.com/problems/lru-cache/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) {
    capacity_ = capacity;
  }
  
  int get(int key) {
    auto it = itMap_.find(key);
    if (it == itMap_.end())
      return -1;
    moveFront(it->second);
    return it->second->second;
  }
  
  void put(int key, int val) {
    auto it = itMap_.find(key);
    if (it != itMap_.end()) {
      it->second->second = val;
      moveFront(it->second);
    } else {
      if (nums_.size() >= capacity_)
        popBack();
      pushFront(key, val);
    }
  }

 private:
  inline void pushFront(int key, int val) {
    nums_.push_front({key, val});
    itMap_[key] = nums_.begin();
  }

  inline void moveFront(list<pair<int, int>>::iterator& iter) {
    nums_.push_front(*iter);
    nums_.erase(iter);
    iter = nums_.begin();
  }

  inline void popBack() {
    itMap_.erase(nums_.back().first);
    nums_.pop_back();
  }

 private:
  unordered_map<int, list<pair<int, int>>::iterator> itMap_;
  list<pair<int, int>> nums_;
  int capacity_;
};

int main(int, char**) {
  LRUCache cache(2);

  #define TEST(a, b) assert(cache.get(a) == b);

  cache.put(1, 1);
  cache.put(2, 2);
  TEST(1,  1);       // returns 1
  cache.put(3, 3);   // evicts key 2
  TEST(2, -1);       // returns -1 (not found)
  cache.put(4, 4);   // evicts key 1
  TEST(1, -1);       // returns -1 (not found)
  TEST(3,  3);       // returns 3
  TEST(4,  4);       // returns 4
  
  return 0;
}

