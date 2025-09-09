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
  int rotatedDigits(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      string num = to_string(i);
      if (num.contains("3") || num.contains("4") || num.contains("7"))
        continue;
      if (num.contains("2") || num.contains("5") || num.contains("6") ||
          num.contains("9"))
        cnt++;
    }
    return cnt;
  }
};

int main() {
  Solution s;
  // int input = 857;
  // auto output = s.rotatedDigits(input);
  return 0;
}
