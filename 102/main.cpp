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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res{};
    if (root == nullptr)
      return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> tmp;
      for (size_t i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        tmp.push_back(node->val);
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
      res.push_back(tmp);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {3, 9, 20, nullopt, nullopt, 15, 7};
  TreeNode *root = createTreeNode(input);
  auto output = s.levelOrder(root);
  return 0;
}
