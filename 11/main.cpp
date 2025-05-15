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
  int maxArea(vector<int> &height) {
    int res = 0;
    int *lptr = &height[0];
    int *rptr = &height[height.size() - 1];
    while (lptr < rptr) {
      res = max(res, int(rptr - lptr) * min(*lptr, *rptr));
      if (*lptr < *rptr)
        lptr++;
      else
        rptr--;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  auto output = s.maxArea(input);
  return 0;
}
