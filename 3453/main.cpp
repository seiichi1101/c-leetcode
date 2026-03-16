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
  double separateSquares(vector<vector<int>>& squares) {
    double sum = 0;
    double bottom = 0, top = 0;
    for (auto sq : squares) {
      sum += (double)sq[2] * sq[2];
      top = max(top, (double)(sq[1] + sq[2]));
    }

    double half = sum / 2;
    double eps = 1e-5;
    while (abs(top - bottom) > eps) {
      double mid = (top + bottom) / 2;

      double tmp_below = 0;
      for (auto&& sq : squares) {
        if (sq[1] < mid) {
          tmp_below += sq[2] * min(mid - sq[1], (double)sq[2]);
        }
      }
      if (tmp_below < half)
        bottom = mid;
      else
        top = mid;
    }

    return top;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input1 = {vector<int>{0, 0, 1}, vector<int>{2, 2, 1}};
  // vector<vector<int>> input1 = {vector<int>{0, 0, 2}, vector<int>{1, 1, 1}};
  vector<vector<int>> input1 = {vector<int>{0, 1000000000, 1000000}};
  assert(s.separateSquares(input1) == 1000500000.00000);
  return 0;
}
