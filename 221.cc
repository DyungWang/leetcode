#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int mLen = matrix.size();
    int nLen = matrix[0].size();
    int mSeq = 0;
    int tSeq = 0;
    vector<vector<int>> seq(mLen+1, vector<int>(nLen+1, 0));
    for (int i = mLen-1; i >= 0; --i) for (int j = nLen-1; j >= 0; --j) {
      if (matrix[i][j] == '0') {
        seq[i][j] = 0;
      } else {
        tSeq = min(seq[i+1][j], seq[i][j+1]);
        tSeq = min(seq[i+1][j+1], tSeq);
        seq[i][j] = tSeq + 1;
      }
      mSeq = max(mSeq, seq[i][j]);
    }
    return mSeq * mSeq;
  }
};

vector<vector<char>> case1 = {
  { '1', '0', '1', '0', '0' },
  { '1', '0', '1', '1', '1' },
  { '1', '1', '1', '1', '1' },
  { '1', '0', '0', '1', '0' }
};

int main(int, char**) {
  Solution solution;
  assert(solution.maximalSquare(case1) == 4);
  cout << "done!" << endl;
  return 0;
}
