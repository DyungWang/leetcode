#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> cmap;
    for (auto n: arr) cmap[n]++;
    vector<int> count; count.reserve(cmap.size());
    for (auto kv: cmap) count.push_back(kv.second);
    sort(count.begin(), count.end());
    int total = 0;
    int res = 0;
    for (auto it = count.rbegin(); it != count.rend(); ++it) {
      total += *it;
      ++res;
      if (total * 2 >= (int)arr.size())
        break;
    }
    return res;
  }
};

struct TestCase {
  vector<int> arr;
  int result;
};

TestCase testCase1 = { {3,3,3,3,5,5,5,2,2,7}, 2 };
TestCase testCase2 = { {7,7,7,7,7,7}, 1 };
TestCase testCase3 = { {1,2,3,4,5,6,7,8,9,10}, 5 };
TestCase testCase4 = { {1000,1000,3,7}, 1 };
TestCase testCase5 = { {1,9}, 1 };

#define TEST_F(testCase) assert(Solution().minSetSize(testCase.arr) == testCase.result)

int main(int, char**) {
  TEST_F(testCase1);
  TEST_F(testCase2);
  TEST_F(testCase3);
  TEST_F(testCase4);
  TEST_F(testCase5);
  return 0;
}

