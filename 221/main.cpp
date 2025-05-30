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

class Node {
public:
  unordered_map<char, Node *> children;
  bool isEnd = false;
};

class WordDictionary {
private:
  Node root;

public:
  WordDictionary() { root = Node(); }

  void addWord(string word) {
    Node *curr = &root;
    for (char c : word) {
      if (!curr->children[c])
        curr->children[c] = new Node();
      curr = curr->children[c];
    }
    curr->isEnd = true;
  }

  bool searchHelper(const string &word, int idx, Node *node) {
    if (!node)
      return false;
    if (idx == word.size())
      return node->isEnd;
    char c = word[idx];
    if (c == '.') {
      for (auto &[k, child] : node->children) {
        if (searchHelper(word, idx + 1, child))
          return true;
      }
      return false;
    } else {
      return searchHelper(word, idx + 1, node->children[c]);
    }
  }
  bool search(string word) { return searchHelper(word, 0, &root); }
};

int main() {
  WordDictionary wordDictionary;
  // wordDictionary.addWord("bad");
  // wordDictionary.addWord("dad");
  // wordDictionary.addWord("mad");
  // wordDictionary.search("pad"); // return False
  // wordDictionary.search("bad"); // return True
  // wordDictionary.search(".ad"); // return True
  // wordDictionary.search("b.."); // return True
  wordDictionary.addWord("a");
  wordDictionary.search("a.");
  return 0;
}
