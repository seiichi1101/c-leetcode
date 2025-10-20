#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
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
  string applySubstitutions(vector<vector<string>> &replacements, string text) {
    unordered_map<char, string> map;
    for (auto &&r : replacements) {
      map[r[0][0]] = r[1];
    }

    bool flag = true;
    while (flag) {
      flag = false;
      for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == '%') {
          string s = map[text[i + 1]];
          text.replace(i, 3, s);
          i += s.size() - 1;
          flag = true;
        }
      }
    }
    return text;
  }
};

int main() {
  Solution s;
  // vector<vector<string>> input1 = {{"A", "abc"}, {"B", "def"}};
  // vector<vector<string>> input1 = {{"A", "bce"}, {"B", "ace"}, {"C",
  // "abc%B%"}}; string text = "%A%_%B%_%C%";
  vector<vector<string>> input1 = {{"P", "jluwndp"}, {"U", "%P%%P%qi"}};
  string text = "%U%_%P%";
  auto output = s.applySubstitutions(input1, text);
  return 0;
}
