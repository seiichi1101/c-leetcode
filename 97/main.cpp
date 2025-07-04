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
  // Memory Limit Exceeded
  // bool isInterleave(string s1, string s2, string s3) {
  //   if (s1.size() == 0 && s2.size() == 0) {
  //     return s3.size() == 0;
  //   } else {
  //     return (s1.size() > 0 && s1[0] == s3[0] &&
  //             isInterleave(s1.substr(1, s1.size()), s2,
  //                          s3.substr(1, s3.size()))) ||
  //            (s2.size() > 0 && s2[0] == s3[0] &&
  //             isInterleave(s1, s2.substr(1, s2.size()),
  //                          s3.substr(1, s3.size())));
  //   }
  // }

  // Time Limit Exceeded
  // bool isInterleave(string s1, string s2, string s3) {
  //   if (s1.size() + s2.size() != s3.size())
  //     return false;

  //   vector<pair<int, int>> stack;
  //   stack.push_back(pair<int, int>{0, 0});
  //   while (!stack.empty()) {
  //     pair<int, int> node = stack.back();
  //     stack.pop_back();

  //     if (node.first == s1.size() && node.second == s2.size() &&
  //         node.first + node.second == s3.size())
  //       return true;
  //     if (node.first < s1.size() &&
  //         s1[node.first] == s3[node.first + node.second])
  //       stack.push_back(pair<int, int>{node.first + 1, node.second});
  //     if (node.second < s2.size() &&
  //         s2[node.second] == s3[node.first + node.second])
  //       stack.push_back(pair<int, int>{node.first, node.second + 1});
  //   }
  //   return false;
  // }

  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;

    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
    for (size_t i = 0; i < s1.size() + 1; i++) {
      for (size_t j = 0; j < s2.size() + 1; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
        } else {
          dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                     (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
      }
    }
    return dp[s1.size()][s2.size()];
  }
};

int main() {
  Solution s;
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  // string s1 = "";
  // string s2 = "b";
  // string s3 = "b";
  auto output = s.isInterleave(s1, s2, s3);
  return 0;
}
