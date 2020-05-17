// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/17
// @link https://leetcode.com/problems/peeking-iterator/

#include <vector>
#include <iostream>
#include "leetcode.h"

using namespace std;

class Iterator {
 public:
	Iterator(const vector<int>& nums) {
    iter = nums.begin();
    end = nums.end();
  }
 	// Iterator(const Iterator& iter);

 	// Returns the next element in the iteration.
	int next() {
    return *(iter++);
  }
	// Returns true if the iteration has more elements.
	bool hasNext() const {
    return iter != end;
  }

 private:
  vector<int>::const_iterator iter;
  vector<int>::const_iterator end;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    if (Iterator::hasNext()) {
      cnxt = new int;
      *cnxt = Iterator::next();
    }
  }
	
  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return cnxt != nullptr ? *cnxt : -1;
  }
	
  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int ret = peek();
    if (Iterator::hasNext())
      *cnxt = Iterator::next();
    else {
      if (cnxt != nullptr) 
        delete cnxt;
      cnxt = nullptr;
    }
    return ret;
  }
	
  bool hasNext() const {
    return cnxt != nullptr;
  }
    
 private:
  int* cnxt = nullptr;
};

void test() {
  vector<int> nums = { 1, 2, 3 };
  PeekingIterator iter(nums);
  std::cout << iter.hasNext() << std::endl;
  std::cout << iter.next() << std::endl;
  std::cout << iter.peek() << std::endl;
  std::cout << iter.next() << std::endl;
  std::cout << iter.next() << std::endl;
  std::cout << iter.hasNext() << std::endl;
}

int main(int, char**) {
  test();
  return 0;
}
