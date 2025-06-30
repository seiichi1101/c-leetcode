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

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return root;
    Node *head = root;
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
      Node *prev = nullptr;
      int size = queue.size();
      for (size_t i = 0; i < size; i++) {
        Node *node = queue.front();
        queue.pop();
        if (prev != nullptr) {
          prev->next = node;
        }
        prev = node;
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
    }

    return head;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 4, 5, null, 7};
  // Node *input = new Node(1, new Node(2), new Node(3), nullptr);
  Node *input = nullptr;
  auto output = s.connect(input);
  return 0;
}
