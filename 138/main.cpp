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
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;
    Node *newHead = new Node(head->val);
    Node *currNewHead = newHead;
    Node *currOriginalHead = head;
    unordered_map<Node *, Node *> originToNewMap{
        {currOriginalHead, currNewHead}};

    while (currOriginalHead->next != nullptr) {
      Node *newNext = new Node(currOriginalHead->next->val);
      currNewHead->next = newNext;
      originToNewMap[currOriginalHead->next] = currNewHead->next;
      currNewHead = currNewHead->next;
      currOriginalHead = currOriginalHead->next;
    }

    currOriginalHead = head;
    currNewHead = newHead;
    while (currOriginalHead != nullptr) {
      if (currOriginalHead->random != nullptr) {
        currNewHead->random = originToNewMap[currOriginalHead->random];
      }
      currNewHead = currNewHead->next;
      currOriginalHead = currOriginalHead->next;
    }

    return newHead;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3};
  auto output = s.test(input);
  return 0;
}
