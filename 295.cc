// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/17
// @link https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
#include <iostream>

using namespace std;

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {
  }
  
  void addNum(int num) {
    if (lower.empty() || lower.top() >= num) {
      lower.push(num);
    } else {
      high.push(num);
    }
    if (high.size() + 1 < lower.size()) {
      high.push(lower.top());
      lower.pop();
    }
    if (lower.size() < high.size()) {
      lower.push(high.top());
      high.pop();
    }
  }
  
  double findMedian() {
    if (lower.size() > high.size())
      return lower.top();
    return lower.top()/2.0 + high.top()/2.0;
  }

 private:
  priority_queue<int, vector<int>, greater<int>> high;
  priority_queue<int, vector<int>, less<int>> lower;
};

void test1() {
  MedianFinder finder;
  finder.addNum(1);
  finder.addNum(2);
  cout << finder.findMedian() << endl;
  finder.addNum(3);
  cout << finder.findMedian() << endl;
  finder.addNum(4);
  cout << finder.findMedian() << endl;
  finder.addNum(5);
  cout << finder.findMedian() << endl;
  finder.addNum(6);
  cout << finder.findMedian() << endl;
}

int main(int, char**) {
  test1();
  return 0;
}
