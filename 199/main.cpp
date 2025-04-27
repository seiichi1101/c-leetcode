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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
      return {};

    vector<int> res;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      res.push_back(queue.back()->val);
      size_t size = queue.size();
      for (size_t i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {1, 2, 3, nullopt, 5, nullopt, 4};
  auto output = s.rightSideView(createTreeNode(input));
  return 0;
}
