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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
      return nullptr;

    int top = preorder[0];
    TreeNode *node = new TreeNode(top);
    auto it = find(inorder.begin(), inorder.end(), top);
    int dist = distance(inorder.begin(), it);

    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + dist);
    vector<int> leftInorder(inorder.begin(), inorder.begin() + dist);
    node->left = buildTree(leftPreorder, leftInorder);

    vector<int> rightPreorder(preorder.begin() + 1 + dist, preorder.end());
    vector<int> rightInorder(inorder.begin() + 1 + dist, inorder.end());
    node->right = buildTree(rightPreorder, rightInorder);
    return node;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {3, 9, 20, 15, 7};
  vector<int> input2 = {9, 3, 15, 20, 7};
  auto output = s.buildTree(input1, input2);
  return 0;
}
