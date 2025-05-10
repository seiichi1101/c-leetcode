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
  int trailingZeroes(int n) {
    // O(N)
    // int cnt = 0;
    // for (size_t i = 5; i < n + 1; i += 5) {
    //   int num = i;
    //   while (num % 5 == 0) {
    //     // count how many 5 have in num
    //     num /= 5;
    //     cnt++;
    //   }
    // }
    // return cnt;

    // O(logN)
    int cnt = 0;
    while (n > 0) {
      n /= 5;
      cnt += n;
    }
    return cnt;
  }
};

int main() {
  Solution s;
  int input = 13;
  // int input = 30;
  auto output = s.trailingZeroes(input);
  return 0;
}
