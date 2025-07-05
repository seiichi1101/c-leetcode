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
  string convert(string s, int numRows) {
    if (numRows <= 1 || numRows >= s.length())
      return s;
    int numCols = s.size() / 2 + 1;
    vector<vector<char>> result(numRows, vector<char>(numCols));

    size_t sIdx = 0;
    for (size_t j = 0; j < numCols; j++) {
      for (size_t i = 0; i < numRows; i++) {
        int div = (numRows - 1);
        if (div == 0 || j % div == 0) {
          if (sIdx < s.size()) {
            result[i][j] = s[sIdx];
            sIdx++;
          }
        } else {
          if (sIdx < s.size()) {
            int a = j % div;
            result[numRows - 1 - a][j] = s[sIdx];
            sIdx++;
          }
          break;
        }
      }
    }

    string res = "";
    for (auto &&row : result) {
      for (auto &&item : row) {
        if (item != '\000')
          res += item;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  // string input = "PAYPALISHIRING";
  // int num = 3;
  // string input = "PAYPALISHIRING";
  // int num = 4;
  string input = "ABC";
  int num = 1;
  auto output = s.convert(input, num);
  return 0;
}
