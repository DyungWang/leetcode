#include <iostream>
#include <vector>

using namespace std;

class TreeAncestor {
 public:
  TreeAncestor(int n, vector<int>& parent) : parents_(20, vector<int>(n, -1)) {
    for (int i = 1; i < n; ++i)
      parents_[0][i] = parent[i];
    for (int i = 1; i < 20; ++i) for (int j = 1; j < n; ++j) {
      int p = parents_[i-1][j];
      if (p != -1) 
        parents_[i][j] = parents_[i-1][p];
    }
  }
    
  int getKthAncestor(int node, int k) {
    for (int i = 0; i < 20; ++i) {
      if ((k & (1 << i))) {
        node = parents_[i][node];
        if (node == -1) return -1;
      }
    }
    return node;
  }
 
 private:
  vector<vector<int>> parents_;
};

void test() {
  vector<int> parents = {-1,0,0,1,1,2,2};
  TreeAncestor tas(parents.size(), parents);
  cout << tas.getKthAncestor(3, 1) << endl;
  cout << tas.getKthAncestor(5, 2) << endl;
  cout << tas.getKthAncestor(6, 3) << endl;
}

int main(int, char**) {
  test();
  return 0;
}


