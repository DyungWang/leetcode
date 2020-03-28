#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    vector<int> place(n, -1);  // the queen in i row place in place[i] col.
    return dfs(place, 0);
  }
 
 private:
  int dfs(vector<int>& place, int m) {
    if (m == place.size())
      return 1;
    
    int ret = 0;
    for (int i = 0; i < place.size(); ++i) {
      place[m] = i;
      if (isValid(place, m))
        ret += dfs(place, m+1);
      place[m] = -1;
    }
    return ret;
  }

  bool isValid(const vector<int>& place, int m) {
    for (int i = 0; i < m; ++i) {
      if (!isValid(i, place[i], m, place[m]))
        return false;
    }
    return true;
  }

  // queen1 in point (a, b)
  // queen2 in point (c, d)
  // check if valid.
  bool isValid(int a, int b, int c, int d) {
    if (b == d) 
      return false;
    return abs(a-c) != abs(b-d);
  }
};


int main(int, char**) {
  Solution solution;
  assert(solution.totalNQueens(4) == 2);
  return 0;  
}
