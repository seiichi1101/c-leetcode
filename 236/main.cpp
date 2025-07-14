#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  TreeNode *ans = nullptr;
  bool _lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
      return false;

    bool left = _lowestCommonAncestor(root->left, p, q);
    bool right = _lowestCommonAncestor(root->right, p, q);

    if (left && right) {
      ans = root;
      return true;
    } else if (root == p || root == q) {
      if (left || right)
        ans = root;
      return true;
    } else {
      return left || right;
    }
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    _lowestCommonAncestor(root, p, q);
    return this->ans;
  }
};

int main() {
  Solution s;
  TreeNode *root = createTreeNode(
      vector<optional<int>>{3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4});
  TreeNode *p = root->left;
  TreeNode *q = root->right;
  auto output = s.lowestCommonAncestor(root, p, q);
  return 0;
}
