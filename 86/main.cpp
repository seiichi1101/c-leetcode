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
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr)
      return head;
    ListNode *lessHead = nullptr;
    ListNode *lessTail = nullptr;
    ListNode *greaterHead = nullptr;
    ListNode *greaterTail = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      if (curr->val < x) {
        if (lessHead == nullptr) {
          lessHead = curr;
          lessTail = curr;
        } else {
          lessTail->next = curr;
          lessTail = lessTail->next;
        }
      } else {
        if (greaterHead == nullptr) {
          greaterHead = curr;
          greaterTail = curr;
        } else {
          greaterTail->next = curr;
          greaterTail = greaterTail->next;
        }
      }
      curr = curr->next;
    }

    if (lessHead != nullptr && greaterHead != nullptr) {
      lessTail->next = greaterHead;
      greaterTail->next = nullptr;
    } else if (lessHead != nullptr) {
      lessTail->next = nullptr;
    } else {
      lessHead = greaterHead;
      greaterTail->next = nullptr;
    }
    return lessHead;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 4, 3, 2, 5, 2};
  // int x = 3;
  // vector<int> input = {2, 1};
  // int x = 2;
  // vector<int> input = {1, 0};
  // int x = 2;
  vector<int> input = {1};
  int x = 0;
  auto output = s.partition(createListNode(input), x);
  return 0;
}
