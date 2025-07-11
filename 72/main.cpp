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
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < dp[i].size(); j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = i + j;
        } else {
          int tmpMin = min(dp[i - 1][j], dp[i][j - 1]);
          dp[i][j] = word1[i - 1] == word2[j - 1]
                         ? min(dp[i - 1][j - 1], tmpMin + 1)
                         : min(dp[i - 1][j - 1] + 1, tmpMin + 1);
        }
      }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
  }
};

int main() {
  Solution s;
  // string input1 = "horse";
  // string input2 = "ros";
  string input1 = "";
  string input2 = "";
  auto output = s.minDistance(input1, input2);
  return 0;
}
