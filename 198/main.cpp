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
  int rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)
      return nums[0];

    vector<int> dp(size);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (size_t i = 2; i < size; i++) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[size - 1];
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 1};
  vector<int> input = {2, 1, 1, 2};
  auto output = s.rob(input);
  return 0;
}
