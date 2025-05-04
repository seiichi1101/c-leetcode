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

// Using Map
// struct Node {
//   unordered_map<char, Node *> children;
// };

// class Trie {

// private:
//   Node node;

// public:
//   Trie() {
//     unordered_map<char, Node *> children;
//     node = Node{children};
//   }

//   void insert(string word) {
//     Node *currNode = &node;
//     for (auto &&c : word) {
//       if (currNode->children.find(c) == currNode->children.end()) {
//         currNode->children[c] = new Node{unordered_map<char, Node *>{}};
//       }
//       currNode = currNode->children[c];
//     }
//     currNode->children['0'] = new Node{unordered_map<char, Node *>{}};
//   }

//   bool search(string word) {
//     Node *currNode = &node;
//     for (auto &&c : word) {
//       if (currNode->children.find(c) == currNode->children.end())
//         return false;
//       else
//         currNode = currNode->children[c];
//     }
//     return currNode->children.find('0') == currNode->children.end() ? false
//                                                                     : true;
//   }

//   bool startsWith(string prefix) {
//     Node *currNode = &node;
//     for (auto &&c : prefix) {
//       if (currNode->children.find(c) == currNode->children.end())
//         return false;
//       else
//         currNode = currNode->children[c];
//     }
//     return true;
//   }
// };

// Using Array
struct Node {
  Node *children[27];
  bool end;
};
class Trie {

private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *currNode = root;
    for (auto &&c : word) {
      if (currNode->children[c - 'a'] == nullptr)
        currNode->children[c - 'a'] = new Node{};
      currNode = currNode->children[c - 'a'];
    }
    currNode->end = true;
  }

  bool search(string word) {
    Node *currNode = root;
    for (auto &&c : word) {
      if (currNode->children[c - 'a'] == nullptr)
        return false;
      else
        currNode = currNode->children[c - 'a'];
    }
    return currNode->end;
  }

  bool startsWith(string prefix) {
    Node *currNode = root;
    for (auto &&c : prefix) {
      if (currNode->children[c - 'a'] == nullptr)
        return false;
      else
        currNode = currNode->children[c - 'a'];
    }
    return true;
  }
};

int main() {
  Trie trie;
  trie.insert("apple");
  cout << trie.search("apple");   // return True
  cout << trie.search("app");     // return False
  cout << trie.startsWith("app"); // return True
  trie.insert("app");
  trie.search("app"); // return True
}
