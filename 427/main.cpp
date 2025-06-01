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
#include <valarray>
#include <vector>

using namespace std;

class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *construct(vector<vector<int>> &grid) {
    int size = grid.size();
    if (size == 1) {
      return new Node(grid[0][0], true);
    }

    int half = size / 2;
    vector<vector<int>> topLeft(half);
    vector<vector<int>> topRight(half);
    vector<vector<int>> bottomLeft(half);
    vector<vector<int>> bottomRight(half);
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        if (i < half) {
          if (j < half) {
            topLeft[i].push_back(grid[i][j]);
          } else {
            topRight[i].push_back(grid[i][j]);
          }
        } else {
          if (j < half) {
            bottomLeft[i - half].push_back(grid[i][j]);
          } else {
            bottomRight[i - half].push_back(grid[i][j]);
          }
        }
      }
    }

    Node *topLeftNode = construct(topLeft);
    Node *topRightNode = construct(topRight);
    Node *bottomLeftNode = construct(bottomLeft);
    Node *bottomRightNode = construct(bottomRight);

    if (topLeftNode->isLeaf == true && topRightNode->isLeaf == true &&
        bottomLeftNode->isLeaf == true && bottomRightNode->isLeaf == true &&
        topLeftNode->val == topRightNode->val &&
        topRightNode->val == bottomLeftNode->val &&
        bottomLeftNode->val == bottomRightNode->val) {
      return new Node(topLeftNode->val, true);
    } else {
      return new Node(1, false, topLeftNode, topRightNode, bottomLeftNode,
                      bottomRightNode);
    }
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {
  //     vector<int>{0, 1},
  //     vector<int>{1, 0},
  // };
  vector<vector<int>> input = {
      vector<int>{1, 1, 1, 1, 0, 0, 0, 0}, vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
      vector<int>{1, 1, 1, 1, 1, 1, 1, 1}, vector<int>{1, 1, 1, 1, 1, 1, 1, 1},
      vector<int>{1, 1, 1, 1, 0, 0, 0, 0}, vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
      vector<int>{1, 1, 1, 1, 0, 0, 0, 0}, vector<int>{1, 1, 1, 1, 0, 0, 0, 0}};
  auto output = s.construct(input);
  return 0;
}
