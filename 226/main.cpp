#include "util.hpp"
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
  TreeNode *invertTree(TreeNode *root) {
    if (root != nullptr) {
      swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
    }
    return root;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {1, 2, 3};
  auto output = s.invertTree(createTreeNode(input));
  return 0;
}
