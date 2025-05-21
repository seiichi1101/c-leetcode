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

class MinStack {
private:
  vector<pair<int, int>> list;

public:
  MinStack() {}

  void push(int val) {
    if (list.size() == 0) {
      list.push_back(pair<int, int>{val, val});
    } else {
      auto [_, lastMin] = list.back();
      list.push_back(pair<int, int>{val, min(val, lastMin)});
    }
  }

  void pop() { list.pop_back(); }

  int top() { return list.back().first; }

  int getMin() { return list.back().second; }
};

int main() {
  MinStack minStack = MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  minStack.getMin(); // return -3
  minStack.pop();
  minStack.top();    // return 0
  minStack.getMin(); // return -2
  return 0;
}
