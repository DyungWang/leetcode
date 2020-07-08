// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/07/08
// @link https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <vector>
#include <fstream>

using namespace std;

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    if (arr.size() % 2 != 0) 
      return false;
    vector<int> cnt(k, 0);
    for (auto a : arr)
      cnt[((a % k) + k) % k]++;
    int l = 1, r = k-1;
    while (l < r) 
      if (cnt[l++] != cnt[r--]) 
        return false;
    if (l > r) 
      return true; 
    return cnt[l] % 2 == 0;
  }
};

struct TestCase {
  vector<int> arr;
  int k;
  bool r;
  bool test() { return r == Solution().canArrange(arr, k); }
};

TestCase testCase1 = {
  {1,2,3,4,5,10,6,7,8,9}, 5, true
};

TestCase testCase2 = {
  {1,2,3,4,5,6}, 7, true
};

TestCase testCase3 = {
  {1,2,3,4,5,6}, 10, false
};

TestCase testCase4 = {
  {-1,1,-2,2,-3,3,-4,4}, 3, true
};


int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  return 0;
}

