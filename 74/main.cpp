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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (n * m == 1)
      return matrix[0][0] == target;
    int s = 0, e = n * m;
    int mid = (e - s) / 2;

    while (s <= e && -1 < mid && mid < n * m) {
      int i = mid / m;
      int j = mid % m;
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] > target) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
      mid = s + (e - s) / 2;
    }

    return false;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {
  //     {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  // vector<vector<int>> input = {{1}};
  // vector<vector<int>> input = {{1, 3}};
  vector<vector<int>> input = {{1, 1}};
  auto output = s.searchMatrix(input, 2);
  return 0;
}
