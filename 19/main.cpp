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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr)
      return nullptr;

    ListNode *tmpN = new ListNode();
    ListNode *tmpHead = tmpN;
    tmpN->next = head;
    ListNode *curr = head;
    int cnt = 1;

    while (curr != nullptr) {
      if (cnt > n) {
        tmpN = tmpN->next;
      }
      curr = curr->next;
      cnt++;
    }

    swap(tmpN->next, tmpN->next->next);

    return tmpHead->next;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 4, 5};
  // int n = 2;
  // vector<int> input = {1};
  // int n = 1;
  // vector<int> input = {1, 2};
  // int n = 1;
  vector<int> input = {1, 2};
  int n = 2;
  auto output = s.removeNthFromEnd(createListNode(input), n);
  return 0;
}
