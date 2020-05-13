// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/12
// @link https://leetcode.com/problems/contains-duplicate-iii/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (t <  0) return false;
    if (k <= 0) return false;
    int64_t w = t + (int64_t)1;
    unordered_map<int64_t, int64_t> buckets;
    for (int i = 0; i < (int)nums.size(); ++i) {
      int key = getKey(nums[i], w);
      if (buckets.count(key) != 0)
        return true;
      if (distance(buckets, key-1, nums[i], w))
        return true;
      if (distance(buckets, key+1, nums[i], w))
        return true;
      if (i >= k)
        buckets.erase(getKey(nums[i-k], w));
      buckets[key] = nums[i];
    } 
    return false;
  }

 private:
  int getKey(int64_t n, int64_t w) {
    if (n < 0) 
      return (n + 1) / w - 1;
    return n / w;
  }

  bool distance(
      unordered_map<int64_t, int64_t>& buckets, 
      int64_t key, int64_t val, int64_t w) {
    auto iter = buckets.find(key);
    if (iter == buckets.end())
      return false;
    return abs(iter->second - val) < w;
  }
};

struct TestCase {
  vector<int> nums;
  int k;
  int t;
  int r;

  bool test() { return r == Solution().containsNearbyAlmostDuplicate(nums, k, t); }
};

TestCase testCase1 = {
  {1,2,3,1}, 3, 0, 1
};

TestCase testCase2 = {
  {1,0,1,1}, 1, 2, 1
};

TestCase testCase3 = {
  {1,5,9,1,5,9}, 2, 3, 0
};

TestCase testCase4 = {
  {2, 1}, 1, 1, 1
};

TestCase testCase5 = {
  {1,5,9,1,5,9}, 2, 3, 0
};

TestCase testCase6 = {
  {1, 2}, 0, 1, 0
};

TestCase testCase7 = {
  {-3, 3}, 2, 4, 0
};

TestCase testCase8 = {
  {0,2147483647}, 1, 2147483647, 1
};

int main(int, char**) {
#define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  TEST(testCase2);
  TEST(testCase3);
  TEST(testCase4);
  TEST(testCase5);
  TEST(testCase6);
  TEST(testCase7);
  TEST(testCase8);
#undef TEST
  return 0;
}




