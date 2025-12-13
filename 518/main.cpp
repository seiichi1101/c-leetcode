#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
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
  // Backtracking
  // void _change(int amount, vector<int> &coins, int &res) {
  //   if (coins.size() == 0)
  //     return;
  //   int v = coins.back();
  //   int cnt = 1;
  //   while (v * cnt <= amount) {
  //     if (v * cnt == amount) {
  //       res++;
  //     } else {
  //       coins.pop_back();
  //       _change(amount - v * cnt, coins, res);
  //       coins.push_back(v);
  //     }
  //     cnt++;
  //   }
  //   coins.pop_back();
  //   _change(amount, coins, res);
  //   coins.push_back(v);
  // }

  // int change(int amount, vector<int> &coins) {
  //   if (amount == 0)
  //     return 1;
  //   unordered_set<int> coins_set(coins.begin(), coins.end());
  //   vector<int> _coins(coins_set.begin(), coins_set.end());
  //   int res = 0;
  //   _change(amount, _coins, res);
  //   return res;
  // }

  // 2DP
  // int change(int amount, vector<int> &coins) {
  //   int n = coins.size();
  //   // dp[i][j]「インデックス i 以降のコインを使って、金額 jを作る方法の数」
  //   vector<vector<unsigned long long>> dp(
  //       n + 1, vector<unsigned long long>(amount + 1));

  //   for (int i = 0; i <= n; i++) {
  //     dp[i][0] = 1;
  //   }

  //   for (int i = n - 1; i >= 0; i--) {
  //     for (int j = 1; j <= amount; j++) {
  //       if (coins[i] > j) {
  //         dp[i][j] = dp[i + 1][j];
  //       } else {
  //         dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
  //       }
  //     }
  //   }

  //   return dp[0][amount] <= INT_MAX ? dp[0][amount] : -1;
  // }

  // DP
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      for (int amt = coins[i]; amt <= amount; amt++) {
        dp[amt] += dp[amt - coins[i]];
      }
    }
    return dp[amount];
  }
  // int change(int amount, vector<int> &coins) {
  //   vector<int> dp(amount + 1);
  //   unordered_set<int> coins_set(coins.begin(), coins.end());
  //   for (auto &&v : coins_set) {
  //     if (v < dp.size())
  //       dp[v] = 1;
  //   }

  //   for (size_t i = 0; i < dp.size(); i++) {
  //     for (auto &&v : coins_set) {
  //       if (i + v < amount) {
  //         dp[i + v] += dp[i];
  //       }
  //     }
  //   }

  //   return dp[amount];
  // }
};

int main() {
  Solution s;
  int amount = 5;
  vector<int> coins = {1, 2, 5};
  int res = 4;
  // int amount = 500;
  // vector<int> coins = {3, 5, 7, 8, 9, 10, 11};
  // int res = 0;
  assert(s.change(amount, coins));
  return 0;
}
