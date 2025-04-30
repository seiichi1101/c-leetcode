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
  int numIslands(vector<vector<char>> &grid) {
    int cnt = 0;
    int h = grid.size();
    int w = grid[0].size();
    vector<pair<int, int>> stack;
    int i = 0;

    while (i < h) {
      int j = 0;
      while (j < w) {
        if (grid[i][j] == '1') {
          stack.push_back(pair(i, j));
          cnt++;
        }
        while (!stack.empty()) {
          auto curr = stack.back();
          stack.pop_back();
          grid[curr.first][curr.second] = '0';
          if (curr.first + 1 < h && grid[curr.first + 1][curr.second] == '1')
            stack.push_back(pair(curr.first + 1, curr.second));
          if (curr.second + 1 < w && grid[curr.first][curr.second + 1] == '1')
            stack.push_back(pair(curr.first, curr.second + 1));
          if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == '1')
            stack.push_back(pair(curr.first - 1, curr.second));
          if (curr.second - 1 >= 0 && grid[curr.first][curr.second - 1] == '1')
            stack.push_back(pair(curr.first, curr.second - 1));
        }
        j++;
      }
      i++;
    }

    return cnt;
  };
};

int main() {
  Solution s;
  // vector<vector<char>> input = {
  //     vector<char>{'1', '1', '0', '0', '0'},
  //     vector<char>{'1', '1', '0', '0', '0'},
  //     vector<char>{'0', '0', '1', '0', '0'},
  //     vector<char>{'0', '0', '0', '1', '1'},
  //     vector<char>{'0', '0', '0', '1', '1'},
  // };
  vector<vector<char>> input = {
      vector<char>{'1', '1', '1'},
      vector<char>{'0', '0', '1'},
      vector<char>{'1', '1', '1'},
  };
  auto output = s.numIslands(input);
  return 0;
}
