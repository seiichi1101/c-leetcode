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
public:
  string reverseWords(string s) {
    string res = "";
    string tmp = "";
    for (int i = s.size() - 1; i > -1; i--) {
      if (s[i] == ' ' && tmp != "") {
        res += tmp + ' ';
        tmp = "";
      }

      if (s[i] != ' ')
        tmp = s[i] + tmp;
    }

    if (tmp == "")
      res.pop_back();
    else
      res += tmp;

    return res;
  }
};

int main() {
  Solution s;
  // string input = "the sky is blue";
  string input = " hello world ";
  auto output = s.reverseWords(input);
  return 0;
}
