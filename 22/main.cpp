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
private:
  bool isValid(string s) {
    vector<char> stack;
    for (auto &&c : s) {
      if (c == '(') {
        stack.push_back(c);
      } else {
        if (stack.empty() || stack.back() != '(')
          return false;
        else
          stack.pop_back();
      }
    }

    return stack.empty();
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    queue<string> queue;
    queue.push("(");
    while (!queue.empty()) {
      string s = queue.front();
      queue.pop();
      if (s.size() == n * 2) {
        if (isValid(s))
          res.push_back(s);
      } else {
        queue.push(s + "(");
        queue.push(s + ")");
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  int input = 3;
  auto output = s.generateParenthesis(input);
  return 0;
}
