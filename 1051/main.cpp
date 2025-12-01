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
  int heightChecker(vector<int> &heights) {
    int cnt = 0;
    int map[101] = {};
    for (auto &&h : heights) {
      map[h]++;
    }

    int idx = 0;
    for (size_t i = 1; i < 101; i++) {
      if (map[i] > 0) {
        while (map[i] > 0) {
          if (heights[idx] != i)
            cnt++;
          map[i]--;
          idx++;
        }
      }
    }
    return cnt;
  }
};

int main() {
  Solution s;
  vector<int> input = {};
  input = {1, 1, 4, 2, 1, 3};
  assert(s.heightChecker(input) == 3);
  input = {5, 1, 2, 3, 4};
  assert(s.heightChecker(input) == 5);
  input = {1, 2, 3, 4, 5};
  assert(s.heightChecker(input) == 0);

  return 0;
}
