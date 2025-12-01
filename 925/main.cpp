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
  bool isLongPressedName(string name, string typed) {
    vector<pair<int, int>> map;

    int i = 1;
    pair<int, int> input(name[0], 1);
    while (i < name.size()) {
      char c = name[i];
      if (name[i - 1] == name[i]) {
        input.second++;
      } else {
        map.push_back(input);
        input = {name[i], 1};
      }
      i++;
    }
    map.push_back(input);

    int j = 0, k = 0;
    while (j < map.size() && k < typed.size()) {
      if (map[j].first == typed[k]) {
        map[j].second--;
        k++;
      } else {
        if (map[j].second > 0) {
          return false;
        } else {
          j++;
        }
      }
    }

    return j >= map.size() - 1 && k >= typed.size() - 1 &&
           map[map.size() - 1].first == typed[typed.size() - 1];
  }

  // Simple Two Pointer Solution
  // bool isLongPressedName(string name, string typed) {
  //   int i = 0, j = 0;
  //   int n = name.size(), m = typed.size();
  //   while (j < m) {
  //     if (i < n && name[i] == typed[j]) {
  //       i++;
  //       j++;
  //     } else if (j > 0 && typed[j] == typed[j - 1])
  //       j++;
  //     else
  //       return false;
  //   }
  //   return i == n;
  // }
};

int main() {
  Solution s;

  assert(s.isLongPressedName("alex", "aaleex") == true);
  assert(s.isLongPressedName("saeed", "ssaaedd") == false);
  assert(s.isLongPressedName("rick", "kric") == false);
  assert(s.isLongPressedName("alex", "aaleexa") == false);
  assert(s.isLongPressedName("alex", "aaleexeex") == false);
  return 0;
}
