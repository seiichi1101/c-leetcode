#include "../util.hpp"
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
  void inorderTraversal(TreeNode *root, vector<int> *list) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left, list);
    list->push_back(root->val);
    inorderTraversal(root->right, list);
  }
  int getMinimumDifference(TreeNode *root) {
    vector<int> list;
    inorderTraversal(root, &list);
    int minimum = INT_MAX;
    for (size_t i = 0; i < list.size() - 1; i++) {
      minimum = min(minimum, list[i + 1] - list[i]);
    }
    return minimum;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {236, 104, 701, nullopt, 227, nullopt, 911};
  auto output = s.getMinimumDifference(createTreeNode(input));
  return 0;
}
