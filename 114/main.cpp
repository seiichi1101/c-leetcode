#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  TreeNode *convert(TreeNode *root) {
    if (root != nullptr) {
      auto r = root->right;
      if (root->left != nullptr) {
        root->right = root->left;
        root->left = nullptr;
        root = this->convert(root->right);
      }
      if (r != nullptr) {
        root->right = r;
        root = this->convert(root->right);
      }
    }
    return root;
  }
  void flatten(TreeNode *root) { this->convert(root); }
};

int main() {
  Solution s;
  vector<optional<int>> list = {1, 2, 5, 3, 4, nullopt, 6};
  auto input = createTreeNode(list);
  s.flatten(input);
  return 0;
}
