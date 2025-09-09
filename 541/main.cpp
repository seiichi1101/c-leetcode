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
  string reverseStr(string s, int k) {
    int i = 0;
    while (i < s.size()) {
      int start = i, end = min(i + k - 1, (int)s.size() - 1);
      while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
      }

      i += 2 * k;
    }

    return s;
  }
};

int main() {
  Solution s;
  auto output = s.reverseStr("abcdefg", 8);
  // auto output = s.reverseStr("abcdefg", 2);
  // auto output = s.reverseStr("abcd", 4);
  // auto output = s.reverseStr("a", 2);
  return 0;
}
