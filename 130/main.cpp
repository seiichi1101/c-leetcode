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
  void solve(vector<vector<char>> &board) {
    int h = board.size();
    int w = board[0].size();
    vector<pair<int, int>> stack;

    for (size_t i = 0; i < h; i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        if (i == 0 || i == h - 1 || j == 0 || j == board[i].size() - 1) {
          if (board[i][j] == 'O')
            stack.push_back(pair(i, j));
        }
      }
    }

    while (!stack.empty()) {
      auto curr = stack.back();
      stack.pop_back();
      board[curr.first][curr.second] = 'T';
      if (curr.first + 1 < h && board[curr.first + 1][curr.second] == 'O')
        stack.push_back(pair(curr.first + 1, curr.second));
      if (curr.second + 1 < w && board[curr.first][curr.second + 1] == 'O')
        stack.push_back(pair(curr.first, curr.second + 1));
      if (curr.first - 1 >= 0 && board[curr.first - 1][curr.second] == 'O')
        stack.push_back(pair(curr.first - 1, curr.second));
      if (curr.second - 1 >= 0 && board[curr.first][curr.second - 1] == 'O')
        stack.push_back(pair(curr.first, curr.second - 1));
    }

    for (auto &&row : board) {
      for (auto &&elem : row) {
        elem = elem == 'T' ? 'O' : 'X';
      }
    }
  }
};

int main() {
  Solution s;
  // vector<vector<char>> input = {
  //     vector<char>{'X', 'X', 'X', 'X'},
  //     vector<char>{'X', 'O', 'O', 'X'},
  //     vector<char>{'X', 'X', 'O', 'X'},
  //     vector<char>{'X', 'O', 'X', 'X'},
  // };
  vector<vector<char>> input = {
      vector<char>{'O', 'O'},
      vector<char>{'O', 'O'},
  };
  s.solve(input);
  return 0;
}
