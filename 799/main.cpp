#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
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
  double champagneTower(int poured, int query_row, int query_glass) {
    double res[102][102];

    res[0][0] = poured;
    for (int i = 0; i < query_row; i++) {
      for (int j = 0; j < i + 1; j++) {
        double val = (res[i][j] - 1.0) / 2.0;
        if (val > 0) {
          res[i + 1][j] += val;
          res[i + 1][j + 1] += val;
        }
      }
    }
    return min(1.0, res[query_row][query_glass]);
  }
};

int main() {
  Solution s;
  auto output = s.champagneTower(25, 6, 1);
  assert(output == 0.5);
  return 0;
}
