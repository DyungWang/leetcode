// @author  wangyangyang<wangyanyang@gmail.com>
// @created 2020/05/29
// @link https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

#include <vector>
#include <unordered_set>
#include "leetcode.h"

using namespace std;

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    int bits = 0;
    return pseudoPalindromicPaths(root, bits);
  }
 
 private:
  int pseudoPalindromicPaths(TreeNode* root, int32_t bits) {
    if (root == nullptr) return 0;
    int32_t ret = 0;
    bits ^= (1 << root->val);
    if (root->left == nullptr && root->right == nullptr)
      ret = bits == 0 || ((bits & (bits-1)) == 0);
    ret += pseudoPalindromicPaths(root->left, bits);
    ret += pseudoPalindromicPaths(root->right, bits);
    return ret;
  }
};

struct TestCase {
  vector<string> tree;
  int res;
  
  bool test() {
    TreeNode* root = createTree(tree);
    auto ret = Solution().pseudoPalindromicPaths(root);
    freeTree(root);
    return ret == res;
  }
};

TestCase testCase1 = {
  { "2", "3", "3", "#", "#", "1", "#", "#", "1", "#", "1", "#", "#" },
  2
};

int main(int, char**) {
  #define TEST(testCase) assert(testCase.test())
  TEST(testCase1);
  return 0;
}
