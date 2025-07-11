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
private:
  bool backtrack(vector<vector<char>> &board, string word, int i, int j) {
    if (word.size() == 0)
      return true;
    if (board[i][j] == word[0]) {
      if (word.size() == 1)
        return true;
      char tmp = board[i][j];
      board[i][j] = ' ';
      if (i - 1 >= 0)
        if (backtrack(board, word.substr(1, word.size()), i - 1, j))
          return true;
      if (i + 1 < board.size())
        if (backtrack(board, word.substr(1, word.size()), i + 1, j))
          return true;
      if (j - 1 >= 0)
        if (backtrack(board, word.substr(1, word.size()), i, j - 1))
          return true;
      if (j + 1 < board[i].size())
        if (backtrack(board, word.substr(1, word.size()), i, j + 1))
          return true;
      board[i][j] = tmp;
    }
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.size() == 0)
      return true;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == word[0]) {
          if (word.size() == 1)
            return true;
          char tmp = board[i][j];
          board[i][j] = ' ';
          if (i - 1 >= 0)
            if (backtrack(board, word.substr(1, word.size()), i - 1, j))
              return true;
          if (i + 1 < board.size())
            if (backtrack(board, word.substr(1, word.size()), i + 1, j))
              return true;
          if (j - 1 >= 0)
            if (backtrack(board, word.substr(1, word.size()), i, j - 1))
              return true;
          if (j + 1 < board[i].size())
            if (backtrack(board, word.substr(1, word.size()), i, j + 1))
              return true;
          board[i][j] = tmp;
        }
      }
    }
    return false;
  }
  // bool exist(vector<vector<char>> &board, string word) {
  //   queue<pair<int, int>> queue;
  //   for (size_t i = 0; i < board.size(); i++) {
  //     for (size_t j = 0; j < board[i].size(); j++) {
  //       if (board[i][j] == word[0]) {
  //         if (word.size() > 1) {
  //           if (i - 1 > 0)
  //             queue.push(pair<int, int>{i - 1, j});
  //           if (i + 1 < board.size())
  //             queue.push(pair<int, int>{i + 1, j});
  //           if (j - 1 > 0)
  //             queue.push(pair<int, int>{i, j - 1});
  //           if (j + 1 < board[i].size())
  //             queue.push(pair<int, int>{i, j + 1});
  //         }
  //       }
  //     }
  //   }
  //   word = word.substr(1, word.size());

  //   while (!queue.empty() && word.size() > 0) {

  //   }

  //   return word.size() == 0;
  // }
};

int main() {
  Solution s;
  // vector<vector<char>> input = {vector<char>{'A', 'B', 'C', 'E'},
  //                               vector<char>{'S', 'F', 'C', 'S'},
  //                               vector<char>{'A', 'D', 'E', 'E'}};
  // string word = "ABCCED";
  // vector<vector<char>> input = {vector<char>{'a', 'b'}, vector<char>{'c',
  // 'd'}}; string word = "abcd";
  // vector<vector<char>> input = {vector<char>{'a'}};
  // string word = "a";
  // vector<vector<char>> input = {vector<char>{'a', 'a'}};
  // string word = "aa";
  vector<vector<char>> input = {vector<char>{'a', 'b'}};
  string word = "ba";
  auto output = s.exist(input, word);
  return 0;
}
