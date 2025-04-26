#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *current = head;

    bool carry = false;
    while (l1 != nullptr || l2 != nullptr) {
      int sum = carry ? 1 : 0;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }

      current->next = new ListNode(sum % 10);
      carry = sum > 9;
      current = current->next;
    }

    if (carry)
      current->next = new ListNode(1);

    return head->next;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {2, 4, 3};
  vector<int> input2 = {5, 6, 4};

  auto output = s.addTwoNumbers(createListNode(input1), createListNode(input2));
  return 0;
}
