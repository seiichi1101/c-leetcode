#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  int minPathSum(vector<vector<int>> &grid) {
    size_t h = grid.size();
    size_t w = grid[0].size();
    vector<vector<int>> dp;
    for (size_t i = 0; i < h; i++) {
      dp.push_back(vector<int>(w, 0));
      for (size_t j = 0; j < w; j++) {
        if (0 < i && 0 < j) {
          dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        } else if (0 < i) {
          dp[i][j] = grid[i][j] + dp[i - 1][j];
        } else if (0 < j) {
          dp[i][j] = grid[i][j] + dp[i][j - 1];
        } else {
          dp[i][j] = grid[i][j];
        }
      }
    }

    return dp[h - 1][w - 1];
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {
  //     vector<int>{1, 3, 1},
  //     vector<int>{1, 5, 1},
  //     vector<int>{4, 2, 1},
  // };
  vector<vector<int>> input = {
      vector<int>{1, 2, 3},
      vector<int>{4, 5, 6},
  };
  auto output = s.minPathSum(input);
  return 0;
}
