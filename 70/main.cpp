#include "../util.hpp"
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
  int climbStairs(int n) {
    int dp[46] = {1, 1};
    for (size_t i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main() {
  Solution s;
  int input = 2;
  auto output = s.climbStairs(input);
  return 0;
}
