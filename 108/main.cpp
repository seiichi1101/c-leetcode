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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    } else {
      int mid = nums.size() / 2;
      TreeNode *node = new TreeNode(nums[mid]);
      vector<int> left(nums.begin(), nums.begin() + mid);
      vector<int> right(nums.begin() + mid + 1, nums.end());
      node->left = sortedArrayToBST(left);
      node->right = sortedArrayToBST(right);
      return node;
    }
  }
};

int main() {
  Solution s;
  vector<int> input = {-10, -3, 0, 5, 9};
  auto output = s.sortedArrayToBST(input);
  return 0;
}
