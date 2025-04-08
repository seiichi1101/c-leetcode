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
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> queue;
    queue.push(root->left);
    queue.push(root->right);

    while (!queue.empty()) {
      TreeNode *n1 = queue.front();
      queue.pop();
      TreeNode *n2 = queue.front();
      queue.pop();

      if (n1 == nullptr && n2 != nullptr) {
        return false;
      } else if (n1 != nullptr && n2 == nullptr) {
        return false;
      } else if (n1 != nullptr && n2 != nullptr) {
        if (n1->val != n2->val) {
          return false;
        } else {
          queue.push(n1->left);
          queue.push(n2->right);
          queue.push(n1->right);
          queue.push(n2->left);
        }
      }
    }

    return true;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {1, 2, 2, 3, 4, 4, 3};
  auto output = s.isSymmetric(createTreeNode(input));
  return 0;
}
