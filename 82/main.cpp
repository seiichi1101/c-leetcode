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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
      return head;
    // こういう偽のheadやtailのnodeをsentinel(番兵)と呼ぶらしい
    ListNode *sentinelHead = new ListNode();
    ListNode *last = sentinelHead;
    ListNode *prev = head;
    ListNode *curr = head;
    bool flag = false;
    while (curr != nullptr) {
      if (prev->val == curr->val) {
        flag = true;
      } else {
        if (!flag) {
          last->next = prev;
          last = last->next;
        }
        flag = false;
      }
      prev = curr;
      curr = curr->next;
    }

    if (!flag) {
      last->next = prev;
      last = last->next;
    }
    last->next = nullptr;
    return sentinelHead->next;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3, 3, 4, 4, 5};
  auto output = s.deleteDuplicates(createListNode(input));
  return 0;
}
