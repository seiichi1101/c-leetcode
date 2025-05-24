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

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *currentHead = head;
    ListNode *startPtr = nullptr;
    ListNode *reversed = nullptr;
    ListNode *reversedLast = nullptr;
    int cnt = 1;
    while (currentHead != nullptr) {
      if (left <= cnt && cnt <= right) {
        if (reversed == nullptr) {
          reversed = new ListNode(currentHead->val);
          reversedLast = reversed;
        } else {
          ListNode *tmp = new ListNode(currentHead->val);
          tmp->next = reversed;
          reversed = tmp;
        }
      }
      if (left - 1 == cnt)
        startPtr = currentHead;
      if (right + 1 == cnt)
        reversedLast->next = currentHead;

      currentHead = currentHead->next;
      cnt++;
    }

    if (startPtr != nullptr) {
      startPtr->next = reversed;
      return head;
    } else {
      return reversed;
    }
  }
};

int main() {
  Solution s;
  // ListNode *input = createListNode(vector<int>{1, 2, 3, 4, 5});
  // auto output = s.reverseBetween(input, 2, 4);
  ListNode *input = createListNode(vector<int>{1, 2, 3, 4});
  auto output = s.reverseBetween(input, 1, 4);
  return 0;
}
