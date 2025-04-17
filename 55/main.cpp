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
public:
  bool canJump(vector<int> &nums) {
    int size = nums.size();
    if (nums[0] == 0 && size > 1)
      return false;
    int maxIdx = 0;
    int i = 0;
    while (i <= maxIdx && i < size) {
      maxIdx = max(maxIdx, i + nums[i]);
      i++;
    }
    return maxIdx >= size - 1;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3};
  auto output = s.canJump(input);
  return 0;
}
