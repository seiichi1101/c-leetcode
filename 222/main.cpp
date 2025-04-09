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
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    } else {
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {1, 2, 3, 4, 5, 6};
  auto output = s.countNodes(createTreeNode(input));
  return 0;
}
