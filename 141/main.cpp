#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head != nullptr ? head->next : nullptr;

    while (slow != nullptr && fast != nullptr) {
      if (slow == fast)
        return true;

      slow = slow->next;
      fast = fast->next != nullptr ? fast->next->next : nullptr;
    }

    return false;
  }
};

int main() {
  Solution s;
  ListNode *a = new ListNode(3);
  ListNode *b = new ListNode(2);
  ListNode *c = new ListNode(0);
  ListNode *d = new ListNode(-4);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = b;
  auto output = s.hasCycle(a);
  return 0;
}
