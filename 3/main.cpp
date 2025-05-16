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

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    size_t size = s.size();
    bool map[128](0);
    int l = 0, r = 0;
    while (r < size) {
      if (map[s[r]] == false) {
        res = max(res, 1 + r - l);
        map[s[r]] = true;
        r++;
      } else {
        map[s[l]] = false;
        l++;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  // string input = "abcabcbb";
  string input = " ";
  auto output = s.lengthOfLongestSubstring(input);
  return 0;
}
