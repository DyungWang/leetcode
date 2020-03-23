// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/03/23

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    string res(dominoes.size(), '.');
    int32_t R = -1;
    int32_t t =  0;
    for (int32_t i = 0; i < (int32_t)dominoes.size(); ++i) {
      if (dominoes[i] == 'R') {
        if (R != -1) 
          while (t < i) res[t++] = 'R';
        R = i;
        t = i;
      }
      if (dominoes[i] == 'L') {
        while (t <= i) {
          int32_t a = R == -1 ? INT32_MAX : (t - R);
          int32_t b = i - t;
          res[t++] = a == b ? '.' : (a > b ? 'L' : 'R');
        }
        R = -1;
      }
    }
    if (R != -1) 
      while (R < dominoes.size()) res[R++] = 'R';
    return res;
  }
};

std::string case1 = ".L.R...LR..L..";
std::string ans1 = "LL.RR.LLRRLL..";

std::string case2 = "RR.L";
std::string ans2 = "RR.L";

int main(int, char**) {
  Solution solution;
  assert(solution.pushDominoes(case1) == ans1);
  assert(solution.pushDominoes(case2) == ans2);
  return 0;
}
