// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/06/10
// @link https://leetcode.com/problems/design-browser-history/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    pages_.resize(101);
    pages_[0] = homepage;
    cur_ = 0;
    last_ = cur_;
  }
  
  void visit(string url) {
    pages_[++cur_] = url;
    last_ = cur_;
  }
  
  string back(int steps) {
    cur_ = max(cur_ - steps, 0);
    return pages_[cur_];
  }
  
  string forward(int steps) {
    cur_ = min(cur_ + steps, last_);
    return pages_[cur_];
  }
 
 private:
  int cur_;
  int last_;
  vector<string> pages_;
};

void test() {
  BrowserHistory browserHistory("leetcode.com");
  browserHistory.visit("google.com");
  browserHistory.visit("facebook.com");
  browserHistory.visit("youtube.com");
  cout << browserHistory.back(1) << endl;
  cout << browserHistory.back(1) << endl;
  cout << browserHistory.forward(1) << endl;
  browserHistory.visit("linkedin.com"); 
  cout << browserHistory.forward(2) << endl;
  cout << browserHistory.back(2) << endl;
  cout << browserHistory.back(7) << endl;
}

int main(int, char**) {
  test();
  return 0;
}
