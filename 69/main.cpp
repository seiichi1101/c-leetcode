#include "../util.hpp"
#include <bitset>
#include <cassert>
#include <climits>
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
  int mySqrt(int x) {
    // liner search
    // long n = 0;
    // while ((n * n) < x) {
    //   n++;
    // }
    // return n * n == x ? n : n - 1;

    // binary search
    if (x < 2) {
      return x;
    }

    int left = 0, right = x;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid < x / mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};

int main() {
  Solution s;
  int input = 4;
  auto output = s.mySqrt(input);
  return 0;
}
