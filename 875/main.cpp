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
  int minEatingSpeed(vector<int> &piles, int h) {
    int minK = 1;
    int maxK = *max_element(piles.begin(), piles.end());

    while (minK < maxK) {
      int nextK = (minK + maxK) / 2;
      int sum = 0;
      for (auto &&elem : piles) {
        sum += ((elem - 1) / nextK) + 1;
      }

      if (sum <= h) {
        maxK = nextK;
      } else {
        minK = nextK + 1;
      }
    }
    return maxK;
  }
};

int main() {
  Solution s;
  // vector<int> piles = {3, 6, 7, 11};
  // int h = 8;
  // vector<int> piles = {30, 11, 23, 4, 20};
  // int h = 5;
  // vector<int> piles = {30, 11, 23, 4, 20};
  // int h = 6;
  // vector<int> piles = {312884470};
  // int h = 312884469;
  vector<int> piles = {332484035, 524908576, 855865114, 632922376, 222257295,
                       690155293, 112677673, 679580077, 337406589, 290818316,
                       877337160, 901728858, 679284947, 688210097, 692137887,
                       718203285, 629455728, 941802184};
  int h = 823855818;

  auto output = s.minEatingSpeed(piles, h);
  return 0;
}
