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
  void setZeroes(vector<vector<int>> &matrix) {
    unordered_map<int, bool> iMap;
    unordered_map<int, bool> jMap;

    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          iMap[i] = true;
          jMap[j] = true;
        }
      }
    }

    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[i].size(); j++) {
        if (iMap[i] || jMap[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

int main() {
  Solution s;
  vector<vector<int>> input = {vector<int>{1, 1, 1}, vector<int>{1, 0, 1},
                               vector<int>{1, 1, 1}};
  s.setZeroes(input);
  return 0;
}
