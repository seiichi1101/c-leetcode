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
  // recursive
  // void inorder(TreeNode *root, vector<int> *list) {
  //   if (root != nullptr) {
  //     if (root->left != nullptr)
  //       this->inorder(root->left, list);
  //     list->push_back(root->val);
  //     if (root->right != nullptr)
  //       this->inorder(root->right, list);
  //   }
  // };
  // int kthSmallest(TreeNode *root, int k) {
  //   vector<int> list;
  //   inorder(root, &list);
  //   return list[k - 1];
  // }

  // iterative
  int kthSmallest(TreeNode *root, int k) {
    vector<TreeNode *> stack;
    while (root != nullptr || !stack.empty()) {
      while (root != nullptr) {
        stack.push_back(root);
        root = root->left;
      }
      root = stack.back();
      stack.pop_back();

      if (k == 1) {
        return root->val;
      }
      k--;
      root = root->right;
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {3, 1, 4, nullopt, 2};
  auto output = s.kthSmallest(createTreeNode(input), 1);
  return 0;
}
