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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      double tmp = 0;
      for (size_t i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        tmp += double(node->val);
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
      res.push_back(tmp / double(size));
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {3, 9, 20, nullopt, nullopt, 15, 7};
  auto output = s.averageOfLevels(createTreeNode(input));
  return 0;
}
