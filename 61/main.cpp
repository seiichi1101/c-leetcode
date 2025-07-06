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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr)
      return head;
    int size = 1;
    ListNode *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
      size++;
    }
    curr->next = head;
    curr = curr->next;

    k = size - (k % size);

    while (k > 1) {
      curr = curr->next;
      k--;
    }
    ListNode *res = curr->next;
    curr->next = nullptr;

    return res;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 4, 5};
  // int k = 2;
  vector<int> input = {0, 1, 2};
  int k = 4;
  auto output = s.rotateRight(createListNode(input), k);
  return 0;
}
