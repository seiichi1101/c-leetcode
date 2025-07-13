#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
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

class BSTIterator {
private:
  vector<TreeNode *> stack;

public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      stack.push_back(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode *node = stack.back();
    stack.pop_back();

    TreeNode *right = node->right;
    while (right != nullptr) {
      stack.push_back(right);
      right = right->left;
    }

    return node->val;
  }

  bool hasNext() { return !stack.empty(); }
};

int main() {
  vector<optional<int>> input = {7, 3, 15, nullopt, nullopt, 9, 20};
  BSTIterator itr(createTreeNode(input));
  auto res1 = itr.next();
  auto res2 = itr.next();
  auto res3 = itr.hasNext();
  return 0;
}
