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
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    unordered_map<Node *, Node *> oldToNew;
    Node *nnode = new Node(node->val);
    oldToNew[node] = nnode;
    vector<Node *> list{node};
    while (!list.empty()) {
      Node *oldNode = list.back();
      list.pop_back();
      Node *newNode = oldToNew[oldNode];

      for (auto &&oldNeighbor : oldNode->neighbors) {
        if (oldToNew.find(oldNeighbor) == oldToNew.end()) {
          Node *newNeighbor = new Node(oldNeighbor->val);
          oldToNew[oldNeighbor] = newNeighbor;
          list.push_back(oldNeighbor);
        }
        newNode->neighbors.push_back(oldToNew[oldNeighbor]);
      }
    }

    return oldToNew[node];
  }
};

int main() {
  Solution s;
  Node *node = new Node();
  auto output = s.cloneGraph(node);
  return 0;
}
