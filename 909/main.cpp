#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
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
  int calcSkip(int n, int num, vector<vector<int>> &board) {
    int quo = (num - 1) / n;
    int rem = (num - 1) % n;
    rem = quo % 2 == 0 ? rem : n - rem - 1;
    int reversedIdx = (n * quo) + rem;
    int i = n - 1 - (reversedIdx / n);
    int j = reversedIdx % n;
    return board[i][j];
  }
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    queue<int> q;
    vector<int> dist(n * n + 1, -1);
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
        int skip = calcSkip(n, next, board);
        int destination = skip != -1 ? skip : next;
        if (dist[destination] == -1) {
          dist[destination] = dist[curr] + 1;
          q.push(destination);
        }
      }
    }
    return dist[n * n];
  }
};

int main() {
  Solution s;
  vector<vector<int>> input = {
      vector<int>{-1, -1, -1, -1, -1, -1}, vector<int>{-1, -1, -1, -1, -1, -1},
      vector<int>{-1, -1, -1, -1, -1, -1}, vector<int>{-1, 35, -1, -1, 13, -1},
      vector<int>{-1, -1, -1, -1, -1, -1}, vector<int>{-1, 15, -1, -1, -1, -1}};
  // vector<vector<int>> input = {vector<int>{-1, -1}, vector<int>{-1, 3}};
  // vector<vector<int>> input = {vector<int>{1, 1, -1}, vector<int>{1, 1, 1},
  //                              vector<int>{-1, 1, 1}};
  // vector<vector<int>> input = {
  //     vector<int>{-1, -1, 2, -1}, vector<int>{14, 2, 12, 3},
  //     vector<int>{4, 9, 1, 11}, vector<int>{-1, 2, 1, 16}};
  // vector<vector<int>> input = {
  //     vector<int>{-1, -1, 2, 21, -1},  vector<int>{16, -1, 24, -1, 4},
  //     vector<int>{2, 3, -1, -1, -1},   vector<int>{-1, 11, 23, 18, -1},
  //     vector<int>{-1, -1, -1, 23, -1},
  // };
  auto output = s.snakesAndLadders(input);
  return 0;
}
