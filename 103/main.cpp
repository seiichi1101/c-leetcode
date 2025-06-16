#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr)
      return vector<vector<int>>{};

    vector<vector<int>> res;
    queue<TreeNode *> queue;
    queue.push(root);

    int cnt = 0;
    while (!queue.empty()) {
      int size = queue.size();
      vector<int> tmp;
      for (size_t i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        tmp.push_back(node->val);
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
      if (cnt % 2 == 1)
        reverse(tmp.begin(), tmp.end());
      res.push_back(tmp);
      cnt++;
    }
    return res;
  }
};

int main() {
  Solution s;
  // vector<optional<int>> input = {3, 9, 20, nullopt, nullopt, 15, 7};
  vector<optional<int>> input = {1, 2, 3, 4, 5, 6, 7};
  auto output = s.zigzagLevelOrder(createTreeNode(input));
  return 0;
}
