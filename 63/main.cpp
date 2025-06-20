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
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int res = 0;
    if (obstacleGrid[0][0] == 1)
      return res;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    // TLE
    // queue<pair<int, int>> queue;
    // queue.push(pair<int, int>{0, 0});
    // while (!queue.empty()) {
    //   pair<int, int> data = queue.front();
    //   queue.pop();
    //   if (obstacleGrid[data.first][data.second] == 0) {
    //     dp[data.first][data.second]++;
    //     if (data.first + 1 < m)
    //       queue.push(pair<int, int>{data.first + 1, data.second});
    //     if (data.second + 1 < n)
    //       queue.push(pair<int, int>{data.first, data.second + 1});
    //   }
    // }

    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          if (i - 1 >= 0)
            dp[i][j] += dp[i - 1][j];
          if (j - 1 >= 0)
            dp[i][j] += dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution s;
  vector<vector<int>> input = {vector<int>{0, 0, 0}, vector<int>{0, 1, 0},
                               vector<int>{0, 0, 0}};
  auto output = s.uniquePathsWithObstacles(input);
  return 0;
}
