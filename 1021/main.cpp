#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
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
public:
  string removeOuterParentheses(string s) {
    string res;
    int cnt = 0;
    int l = 0, r = 0;
    while (r < s.size()) {
      if (s[r] == '(')
        cnt++;
      else
        cnt--;

      if (cnt == 0) {
        res += s.substr(l + 1, r - l - 1);
        l = r + 1;
      }

      r++;
    }

    return res;
  }
};

int main() {
  Solution s;
  // string input = "(()())(())(()(()))";
  // auto output = s.removeOuterParentheses(input);
  return 0;
}
