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

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int i = 0, j = 0;
    int sum = nums[i];
    int res = INT_MAX;
    while (i < nums.size() && j < nums.size()) {
      if (target <= sum) {
        res = min(res, j - i + 1);
      }

      if (sum < target) {
        j++;
        if (j >= nums.size()) {
          break;
        } else {
          sum += nums[j];
        }
      } else {
        i++;
        if (i >= nums.size()) {
          break;
        } else {
          sum -= nums[i - 1];
        }
      }
    }

    return res == INT_MAX ? 0 : res;
  }
};

int main() {
  Solution s;
  // int target = 7;
  // vector<int> nums = {2, 3, 1, 2, 4, 3};
  // int target = 11;
  // vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  vector<int> nums = {1, 2, 3, 4, 5};
  auto output = s.minSubArrayLen(target, nums);
  return 0;
}
