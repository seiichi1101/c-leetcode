#include <optional>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

TreeNode *createTreeNode(const vector<optional<int>> &values) {
  if (values.empty())
    return nullptr;

  vector<TreeNode *> nodes(values.size(), nullptr);
  for (size_t i = 0; i < values.size(); ++i) {
    if (values[i].has_value()) {
      nodes[i] = new TreeNode(values[i].value());
    }
  }
  for (size_t i = 0, pos = 1; pos < values.size(); ++i) {
    if (nodes[i] != nullptr) {
      if (pos < values.size())
        nodes[i]->left = nodes[pos++];
      if (pos < values.size())
        nodes[i]->right = nodes[pos++];
    }
  }
  return nodes[0];
}

struct ListNode {
  int val;
  ListNode *next = nullptr;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() { delete next; }
};

ListNode *createListNode(const vector<int> &vec) {
  if (vec.empty())
    return nullptr;

  ListNode *head = new ListNode(vec[0]);
  ListNode *current = head;

  for (size_t i = 1; i < vec.size(); ++i) {
    current->next = new ListNode(vec[i]);
    current = current->next;
  }

  return head;
}
