#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  bool isValidSudoku(vector<vector<char>> &board) {
    int row[9][9] = {false}, column[9][9] = {false}, block[9][9] = {false};

    for (size_t i = 0; i < 9; i++) {
      for (size_t j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';

          // row
          if (row[j][num]) {
            return false;
          } else {
            row[j][num] = true;
          }

          // column
          if (column[i][num]) {
            return false;
          } else {
            column[i][num] = true;
          }

          // block
          int k = (i / 3) * 3 + (j / 3);
          if (block[k][num]) {
            return false;
          } else {
            block[k][num] = true;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  Solution s;
  // vector<vector<char>> input = {
  //     vector<char>{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
  //     vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
  //     vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
  //     vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
  //     vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
  //     vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
  //     vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
  //     vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
  //     vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  vector<vector<char>> input = {
      vector<char>{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
      vector<char>{'2', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'3', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'4', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'5', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'6', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'8', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
  auto output = s.isValidSudoku(input);

  return 0;
}
