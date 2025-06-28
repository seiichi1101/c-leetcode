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
  // ルール1:
  //  空いているマスの隣に石がちょうど3個あれば、次のターンでそのマスに石を置く。
  // ルール2:
  //  石の隣に石が2個または3個あれば、その石は次のターンでもそのままにしておく。
  // ルール3:
  //  石の隣に石が1個以下しかなければ、その石は次のターンで取り除く。
  // ルール4:
  //  石の隣に石が4個以上あれば、その石は次のターンで取り除く。
  void gameOfLife(vector<vector<int>> &board) {
    int n = board.size();
    int m = board[0].size();

    for (auto &&row : board) {
      for (auto &&item : row) {
        item += 2;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int sum = 0;
        sum += i - 1 > -1 && j - 1 > -1 && board[i - 1][j - 1] % 2 == 1 ? 1 : 0;
        sum += i - 1 > -1 && board[i - 1][j] % 2 == 1 ? 1 : 0;
        sum += i - 1 > -1 && j + 1 < m && board[i - 1][j + 1] % 2 == 1 ? 1 : 0;
        sum += j - 1 > -1 && board[i][j - 1] % 2 == 1 ? 1 : 0;
        sum += j + 1 < m && board[i][j + 1] % 2 == 1 ? 1 : 0;
        sum += i + 1 < n && j - 1 > -1 && board[i + 1][j - 1] % 2 == 1 ? 1 : 0;
        sum += i + 1 < n && board[i + 1][j] % 2 == 1 ? 1 : 0;
        sum += i + 1 < n && j + 1 < m && board[i + 1][j + 1] % 2 == 1 ? 1 : 0;

        if (board[i][j] % 2 == 1 && sum < 2) {
          board[i][j] -= 2;
        } else if (board[i][j] % 2 == 1 && sum > 3) {
          board[i][j] -= 2;
        } else if (board[i][j] % 2 == 0 && sum == 3) {
          board[i][j] += 2;
        }
      }
    }

    for (auto &&row : board) {
      for (auto &&item : row) {
        item = item > 2 ? 1 : 0;
      }
    }
  }
};

int main() {
  Solution s;
  vector<vector<int>> input = {vector<int>{0, 1, 0}, vector<int>{0, 0, 1},
                               vector<int>{1, 1, 1}, vector<int>{0, 0, 0}};
  s.gameOfLife(input);
  return 0;
}
