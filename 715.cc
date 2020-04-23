// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/04/23
// @link https://leetcode.com/problems/range-module/

#include <map>
#include <iostream>

using namespace std;

class RangeModule {
 public:
  RangeModule() {}
  
  void addRange(int left, int right) {
    auto iter = rangeMap_.lower_bound(left);
    while (iter != rangeMap_.end() && iter->second <= right) {
      right = max(right, iter->first);
      left = min(left, iter->second);
      iter = rangeMap_.erase(iter);
    }
    rangeMap_[right] = left;
  }
  
  bool queryRange(int left, int right) {
    auto iter = rangeMap_.upper_bound(left); 
    if (iter == rangeMap_.end())
      return false;
    return iter->first >= right && iter->second <= left;
  }
  
  void removeRange(int left, int right) {
    auto iter = rangeMap_.upper_bound(left);
    if (iter == rangeMap_.end())
      return;
    auto pleft = iter->second;
    while (iter != rangeMap_.end() && right >= iter->first)
      iter = rangeMap_.erase(iter);
    if (iter != rangeMap_.end() && iter->second < right) 
      iter->second = right;
    if (pleft < left) rangeMap_[left] = pleft;
  }
 
 private:
  map<int, int> rangeMap_;
};

int main(int, char**) {
  RangeModule module;
  module.addRange(14,100);
  module.removeRange(1,8);
  module.queryRange(77,80);
  module.queryRange(8, 43);
  return 0;
}


