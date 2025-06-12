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
  void rotate(vector<vector<int>> &matrix) {
    int size = matrix.size();
    if (size <= 1)
      return;
    int s = 0, e = size - 1;
    while (s < e) {
      int tl[2] = {s, s}, tr[2] = {s, e}, br[2] = {e, e}, bl[2] = {e, s};
      for (size_t i = 0; i < e - s; i++) {
        int tmp = matrix[tl[0]][tl[1] + i];
        swap(tmp, matrix[tr[0] + i][tr[1]]);
        swap(tmp, matrix[br[0]][br[1] - i]);
        swap(tmp, matrix[bl[0] - i][bl[1]]);
        swap(tmp, matrix[tl[0]][tl[1] + i]);
      }
      s++, e--;
    }
  }
};

int main() {
  Solution s;
  vector<vector<int>> input = {vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
                               vector<int>{7, 8, 9}};
  s.rotate(input);
  return 0;
}
