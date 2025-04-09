#include "../util.hpp"
#include <cassert>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode();
    ListNode *current = head;

    while (list1 != nullptr || list2 != nullptr) {
      if (list1 == nullptr) {
        current->next = new ListNode(list2->val);
        list2 = list2->next;
      } else if (list2 == nullptr) {
        current->next = new ListNode(list1->val);
        list1 = list1->next;
      } else if (list1->val < list2->val) {
        current->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        current->next = new ListNode(list2->val);
        list2 = list2->next;
      }

      current = current->next;
    }

    return head->next;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {1, 2, 4};
  vector<int> input2 = {1, 3, 4};
  auto output = s.mergeTwoLists(createListNode(input1), createListNode(input2));
  return 0;
}
