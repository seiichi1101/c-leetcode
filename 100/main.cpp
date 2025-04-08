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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p != nullptr && q != nullptr) {
      if (p->val != q->val) {
        return false;
      } else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
      }
    } else if (p != nullptr && q == nullptr) {
      return false;
    } else if (p == nullptr && q != nullptr) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  Solution s;
  vector<optional<int>> input1 = {1, 2, 3};
  vector<optional<int>> input2 = {1, 2, 3};
  auto output = s.isSameTree(createTreeNode(input1), createTreeNode(input2));
  return 0;
}
