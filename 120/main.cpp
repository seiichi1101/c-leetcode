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
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.size() == 1)
      return triangle[0][0];
    int res = INT_MAX;
    vector<vector<int>> dp = {triangle[0]};
    for (int i = 1; i < triangle.size(); i++) {
      dp.push_back(vector<int>());
      for (int j = 0; j < triangle[i].size(); j++) {
        if (j - 1 > -1 && j < dp[i - 1].size())
          dp[i].push_back(triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]));
        else if (j - 1 > -1)
          dp[i].push_back(triangle[i][j] + dp[i - 1][j - 1]);
        else
          dp[i].push_back(triangle[i][j] + dp[i - 1][j]);

        if (i == triangle.size() - 1) {
          res = min(res, dp[i][j]);
        }
      }
    }

    return res;
  }
};
int main() {
  Solution s;
  vector<vector<int>> input = {vector<int>{2}, vector<int>{3, 4},
                               vector<int>{5, 6, 7}, vector<int>{4, 1, 8, 3}};
  auto output = s.minimumTotal(input);
  return 0;
}
