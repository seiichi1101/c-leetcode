#include "../util.hpp"
#include <cassert>
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
  bool preOrder(TreeNode *root, int targetSum, int sum) {
    if (root == nullptr) {
      return false;
    } else {
      int tmpSum = (root->val + sum);
      if (root->left == nullptr && root->right == nullptr) {
        return tmpSum == targetSum;
      } else {
        return preOrder(root->left, targetSum, tmpSum) ||
               preOrder(root->right, targetSum, tmpSum);
      }
    }
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    return preOrder(root, targetSum, 0);
  }
};

int main() {
  Solution s;
  // vector<optional<int>> input = {5, 4, 8,       11,      nullopt, 13, 4,
  //                                7, 2, nullopt, nullopt, nullopt, 1};
  // auto output = s.hasPathSum(createTreeNode(input), 22);

  vector<optional<int>> input = {-2, nullopt, -3};
  auto output = s.hasPathSum(createTreeNode(input), -5);

  // auto output = s.hasPathSum(nullptr, 0);
  return 0;
}
