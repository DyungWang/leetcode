#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Context {
 public:
  Context(const vector<int>& arr, int d)
      : arr(arr), stp(arr.size(), 0), maxSteps(d) {}
  
  int getMaxJumps(int i) {
    if (stp[i] != 0) 
      return stp[i];
    // jump to left.
    for (int j=i-1; j >= 0 && i-j <= maxSteps; --j) {
      if (arr[j] >= arr[i]) 
        break;
      stp[i] = max(stp[i], getMaxJumps(j));
    }
    // jump to right.
    for (int j=i+1; j < arr.size() && j-i <= maxSteps; ++j) {
      if (arr[j] >= arr[i]) 
        break;
      stp[i] = max(stp[i], getMaxJumps(j));
    }
    return ++stp[i]; 
  }
 
 private:
  vector<int> arr;
  vector<int> stp;
  int maxSteps;
};

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    Context context(arr, d);
    int ret = 0;
    for (int i = 0; i < arr.size(); ++i)
      ret = max(ret, context.getMaxJumps(i));
    return ret;
  }
};

vector<int> case1 = { 3, 3, 3, 3, 3 };
vector<int> case2 = { 7, 6, 5, 4, 3, 2, 1 };
vector<int> case3 = { 7, 1, 7, 1, 7, 1 };
vector<int> case4 = { 6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12 };

int main(int, char**) {
  Solution solution;
  // assert(solution.maxJumps(case1, 3) == 1);
  // assert(solution.maxJumps(case2, 3) == 7);
  // assert(solution.maxJumps(case3, 3) == 2);
  assert(solution.maxJumps(case4, 2) == 4);
  return 0;
}
