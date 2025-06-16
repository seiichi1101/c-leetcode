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
  static const unordered_set<string> op;

public:
  int evalRPN(vector<string> &tokens) {
    vector<string> stack;
    for (auto &&t : tokens) {
      if (op.find(t) == op.end()) {
        stack.push_back(t);
      } else {
        int tmp = 0;
        int a = stoi(stack.back());
        stack.pop_back();
        int b = stoi(stack.back());
        stack.pop_back();

        if (t == "+")
          tmp = b + a;
        else if (t == "-")
          tmp = b - a;
        else if (t == "*")
          tmp = b * a;
        else
          tmp = b / a;

        stack.push_back(to_string(tmp));
      }
    }
    return stoi(stack[0]);
  }
};
const unordered_set<string> Solution::op = {"+", "-", "*", "/"};

int main() {
  Solution s;
  // vector<string> input = {"2", "1", "+", "3", "*"};
  vector<string> input = {"4", "13", "5", "/", "+"};
  // vector<string> input = {"4", "-2", "/", "2", "-3", "-", "-"};
  auto output = s.evalRPN(input);
  return 0;
}
