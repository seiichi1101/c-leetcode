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
  int maxDistToClosest(vector<int> &seats) {
    int maxDiff = 0;
    int cnt = 0;
    bool init = true;
    for (auto &&seat : seats) {
      if (seat > 0) {
        if (init) {
          maxDiff = max(maxDiff, cnt * 2);
          init = false;
        } else {
          maxDiff = max(maxDiff, cnt);
        }
        cnt = 0;
      } else {
        cnt++;
      }
    }
    maxDiff = max(maxDiff, cnt * 2);

    return (maxDiff - 1) / 2 + 1;
  }
};

int main() {
  Solution s;
  // vector<int> input = {0, 0, 1};
  // auto output = s.maxDistToClosest(input);
  return 0;
}
