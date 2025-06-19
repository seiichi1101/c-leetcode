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
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;
    int size = 10001;
    int dp[size];
    for (size_t i = 0; i < size; i++) {
      if (find(coins.begin(), coins.end(), i) != coins.end())
        dp[i] = 1;
      else
        dp[i] = 0;
    }

    for (int i = 1; i <= amount; i++) {
      for (auto &&c : coins) {
        if (i - c > 0 && dp[i - c] != 0) {
          if (dp[i] == 0)
            dp[i] = dp[i - c] + 1;
          else
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return dp[amount] == 0 ? -1 : dp[amount];
  }
};

int main() {
  Solution s;
  // vector<int> input1 = {1, 2, 5};
  // int input2 = 11;
  vector<int> input1 = {2};
  int input2 = 3;
  auto output = s.coinChange(input1, input2);
  return 0;
}
