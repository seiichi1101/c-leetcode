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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    queue<TreeNode *> queue;
    queue.push(root);
    int c = 0;
    while (!queue.empty()) {
      int size = queue.size();
      for (size_t i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
      c++;
    }
    return c;
  }
};

int main() {
  Solution s;
  // vector<optional<int>> input = {3, 9, 20, nullopt, nullopt, 15, 7};
  vector<optional<int>> input = {1, 2, 3, 4, nullopt, nullopt, 5};
  s.maxDepth(createTreeNode(input));
  return 0;
}
