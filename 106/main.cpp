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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    size_t size = inorder.size();
    if (size == 0)
      return nullptr;
    if (size == 1)
      return new TreeNode(inorder[0]);

    int rootVal = postorder[size - 1];
    TreeNode *root = new TreeNode(rootVal);

    size_t mid = 0;
    for (size_t i = 0; i < size; i++) {
      if (inorder[i] == rootVal) {
        mid = i;
        break;
      }
    }

    vector<int> newLeftInorder(inorder.begin(), inorder.begin() + mid);
    vector<int> newRightInorder(inorder.begin() + mid + 1, inorder.end());
    vector<int> newLeftPostorder(postorder.begin(), postorder.begin() + mid);
    vector<int> newRightPostorder(postorder.begin() + mid, postorder.end() - 1);
    root->left = buildTree(newLeftInorder, newLeftPostorder);
    root->right = buildTree(newRightInorder, newRightPostorder);
    return root;
  }
};

int main() {
  Solution s;
  // vector<int> input1 = {9, 3, 15, 20, 7};
  // vector<int> input2 = {9, 15, 7, 20, 3};
  vector<int> input1 = {2, 3, 1};
  vector<int> input2 = {3, 2, 1};
  auto output = s.buildTree(input1, input2);
  return 0;
}
