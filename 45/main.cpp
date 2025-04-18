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
  int jump(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)
      return 0;

    int maxJump = nums[0];
    int nextPos = maxJump;
    int step = 1;
    for (int i = 1; i < size - 1; i++) {
      maxJump = max(maxJump, i + nums[i]);

      if (i == nextPos) {
        step++;
        nextPos = maxJump;
      }
    }
    return step;
  }
};

int main() {
  Solution s;
  vector<int> input = {4, 1, 1, 3, 1, 1, 1};
  auto output = s.jump(input);
  return 0;
}
