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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int hs = -1, ws = -1;
    int he = matrix.size(), we = matrix[0].size();
    enum Arrow { Right, Down, Left, Up };

    int h = 0, w = 0;
    vector<int> res = {matrix[h][w]};

    Arrow arrow;
    if (we > 1) {
      w++;
      arrow = Arrow::Right;
    } else {
      h++;
      arrow = Arrow::Down;
    }
    while (hs < h && h < he && ws < w && w < we) {
      switch (arrow) {
      case Arrow::Right:
        if (w < we - 1) {
          res.push_back(matrix[h][w++]);
        } else {
          res.push_back(matrix[h][w]);
          hs++;
          h++;
          arrow = Arrow::Down;
        }
        break;
      case Arrow::Down:
        if (h < he - 1) {
          res.push_back(matrix[h++][w]);
        } else {
          res.push_back(matrix[h][w]);
          we--;
          w--;
          arrow = Arrow::Left;
        }
        break;
      case Arrow::Left:
        if (w > ws + 1) {
          res.push_back(matrix[h][w--]);
        } else {
          res.push_back(matrix[h][w]);
          he--;
          h--;
          arrow = Arrow::Up;
        }
        break;
      case Arrow::Up:
        if (h > hs + 1) {
          res.push_back(matrix[h--][w]);
        } else {
          res.push_back(matrix[h][w]);
          ws++;
          w++;
          arrow = Arrow::Right;
        }
        break;
      default:
        break;
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
  //                              vector<int>{7, 8, 9}};
  vector<vector<int>> input = {vector<int>{3}, vector<int>{2}};
  auto output = s.spiralOrder(input);
  return 0;
}
