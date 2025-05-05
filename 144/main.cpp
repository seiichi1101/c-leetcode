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
  // Brute Force
  // public:
  //   ListNode *sortList(ListNode *head) {
  //     ListNode *currHead = head;
  //     while (currHead != nullptr) {
  //       ListNode *currNode = currHead;
  //       while (currNode->next != nullptr) {
  //         currNode = currNode->next;
  //         if (currHead->val > currNode->val)
  //           swap(currHead->val, currNode->val);
  //       }
  //       currHead = currHead->next;
  //     }
  //     return head;
  //   }

  // Merge Sort
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *mid = this->gedMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
  }
  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *head = new ListNode();
    ListNode *currHead = head;
    while (left != nullptr || right != nullptr) {
      if (left != nullptr && right != nullptr) {
        if (left->val < right->val) {
          currHead->next = left;
          left = left->next;
        } else {
          currHead->next = right;
          right = right->next;
        }
      } else if (left == nullptr) {
        currHead->next = right;
        right = right->next;
      } else {
        currHead->next = left;
        left = left->next;
      }
      currHead = currHead->next;
    }
    currHead = nullptr;
    return head->next;
  }

  ListNode *gedMid(ListNode *head) {
    ListNode *midPrev = new ListNode(0, head);
    while (head != nullptr && head->next != nullptr) {
      midPrev = midPrev->next;
      head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
  }
};

int main() {
  Solution s;
  vector<int> input = {4, 2, 1, 3};
  auto output = s.sortList(createListNode(input));
  return 0;
}
