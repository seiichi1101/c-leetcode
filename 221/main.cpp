#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  int maximalSquare(vector<vector<char>> &matrix) {
    int res = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), false));
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[i].size(); j++) {
        if ((i == 0 || j == 0)) {
          if (matrix[i][j] == '1') {
            dp[i][j] = 1;
            res = 1;
          }
        }
      }
    }

    for (size_t i = 1; i < matrix.size(); i++) {
      for (size_t j = 1; j < matrix[i].size(); j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
          res = max(res, dp[i][j]);
        }
      }
    }

    return res * res;
  }
};

int main() {
  Solution s;
  // vector<vector<char>> input = {
  //     vector<char>{'1', '0', '1', '0', '0'},
  //     vector<char>{'1', '0', '1', '1', '1'},
  //     vector<char>{'1', '1', '1', '1', '1'},
  //     vector<char>{'1', '0', '0', '1', '0'},
  // };
  vector<vector<char>> input = {
      vector<char>{'0'},
  };
  auto output = s.maximalSquare(input);
  return 0;
}
