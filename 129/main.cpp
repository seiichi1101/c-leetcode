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
  int sumNumbers(TreeNode *root) {
    int sum = 0;
    vector<pair<int, TreeNode *>> stack;
    stack.push_back(pair<int, TreeNode *>{0, root});
    while (!stack.empty()) {
      pair<int, TreeNode *> node = stack.back();
      stack.pop_back();
      if (node.second->left == nullptr && node.second->right == nullptr) {
        sum += (node.first * 10 + node.second->val);
      } else {
        if (node.second->left != nullptr) {
          stack.push_back(pair<int, TreeNode *>{
              node.first * 10 + node.second->val, node.second->left});
        }
        if (node.second->right != nullptr) {
          stack.push_back(pair<int, TreeNode *>{
              node.first * 10 + node.second->val, node.second->right});
        }
      }
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<optional<int>> input = {1, 2, 3};
  auto output = s.sumNumbers(createTreeNode(input));
  return 0;
}
