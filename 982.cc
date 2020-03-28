#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

class Solution {
 public:
  int countTriplets(vector<int>& A) {
    vector<int> cnt(1 << 16, 0);
    int len = A.size();
    int res = 0;
    for (int i = 0; i < len; ++i) for (int j = 0; j < len; ++j)
      cnt[A[i] & A[j]]++;

    // 当j & A[i] == 0, 必有cnt[j]种与A[i]相关的组合能够等于0
    // 有j & A[i] == 0, 则 j 的为1的比特位只能与~A[i]为1的比特位组成
    // 所以只需要遍历这些元素即可
    for (int i = 0; i < len; ++i) {
      int t = (~A[i]) & ((1 << 16) - 1);
      for (int j = t; j != 0; j = (j-1)&t)
        res += cnt[j];
      res += cnt[0];
    }
    return res;
  }
};

vector<int> case1 = { 1, 2, 3 };

int main(int, char**) {
  Solution solution;
  assert(solution.countTriplets(case1) == 12);
  return 0;
}
