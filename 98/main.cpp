#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <optional>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool valid(TreeNode *root, long minVal, long maxVal) {
    if (root == nullptr)
      return true;
    if (root->val <= minVal || maxVal <= root->val)
      return false;

    return valid(root->left, minVal, min(long(root->val), maxVal)) &&
           valid(root->right, max(long(root->val), minVal), maxVal);
  }
  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }
};

int main() {
  Solution s;
  vector<optional<int>> input = {2147483647};
  // vector<optional<int>> input = {2, 2, 2};
  // vector<optional<int>> input = {5, 1, 4, nullopt, nullopt, 3, 6};
  // vector<optional<int>> input = {2, 1, 3};
  TreeNode *root = createTreeNode(input);
  auto output = s.isValidBST(root);
  return 0;
}
