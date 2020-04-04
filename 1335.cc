#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    // 使用 dp[i][j] 表示从第 i 个job开始到，时间为 j 天时，完成所有任务最小的 diffculty
    // j == 0:
    //    dp[i][j] = -1
    // j >= 1:
    //    for each a in i -> jobD.len:
    //       max(jobD[i:a]) + dp[a][j-1
    vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1, 0));
    vector<int> md(jobDifficulty.size(), 0);

    for (int i = 0; i < jobDifficulty.size(); ++i) dp[i][0] = -1;
    for (int i = jobDifficulty.size() - 1; i >= 0; --i) {
      for (int j = 1; j <= d; ++j) {
        if (jobDifficulty.size() - i < j) {
          dp[i][j] = -1;
          continue;
        }
        md[i] = jobDifficulty[i];
        for (int a = i+1; a < jobDifficulty.size(); ++a)
          md[a] = max(md[a-1], jobDifficulty[a]);
        dp[i][j] = INT32_MAX;
        for (int a = i+1; a < jobDifficulty.size(); ++a) if (dp[a][j-1] != -1) 
          dp[i][j] = min(dp[i][j], md[a-1]+dp[a][j-1]);
        if (j == 1) dp[i][j] = md.back();
      }
    }
    return dp[0][d];
  }
};

struct TestCase {
  vector<int> difficulty;
  int days;
  int result;
};

TestCase case1 = { { 1, 1, 1 }, 3, 3 };
TestCase case2 = { { 7, 1, 7, 1, 7, 1 }, 3, 15 };
TestCase case3 = { { 11, 111, 22, 222, 33, 333, 44, 444 }, 6, 843 };
TestCase case4 = { { 1, 1, 1 }, 4, -1 };

int main(int, char**) {
  Solution solution;
  assert(solution.minDifficulty(case1.difficulty, case1.days) == case1.result);
  assert(solution.minDifficulty(case2.difficulty, case2.days) == case2.result);
  assert(solution.minDifficulty(case3.difficulty, case3.days) == case3.result);
  assert(solution.minDifficulty(case4.difficulty, case4.days) == case4.result);
  return 0;
}
