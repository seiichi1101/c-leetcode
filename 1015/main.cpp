#include "../util.hpp"
#include <algorithm>
#include <assert.h>
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
  int smallestRepunitDivByK(int k) {
    if (k % 2 == 0)
      return -1;

    int remainder = 1;
    int cnt = 1;
    unordered_set<int> seen;
    while (remainder % k != 0) {
      remainder = (remainder * 10 + 1) % k;
      if (seen.find(remainder) == seen.end())
        seen.insert(remainder);
      else
        return -1;
      cnt++;
    }
    return cnt;

    // Optimized
    // 余り(remainder) の取りうる値が、[1...k-1]なので、
    // i<=kの間(k回繰り返す間)に、 remainderが0にならなければ、
    // どちらにせよ、どこかの[1...k-1]の値で繰り返しが発生するため、
    // i<=kのループで十分という理屈
    // for (size_t i = 1;i <= k; i++) {
    //   remainder = (remainder * 10 + 1) % k;
    //   if (remainder == 0) {
    //     return i;
    //   }
    // }
    // return -1;
  }
};

int main() {
  Solution s;
  // assert(s.smallestRepunitDivByK(1) == 1);
  assert(s.smallestRepunitDivByK(3) == 3);
  return 0;
}
