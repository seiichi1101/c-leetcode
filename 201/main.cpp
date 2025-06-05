#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  int _range(int left, int right, int mid, int diff) {
    if (diff == 0)
      return 0;

    if (mid <= left) {
      return mid | _range(left, right, mid + (diff / 2), diff / 2);
    } else if (right < mid) {
      return _range(left, right, mid - (diff / 2), diff / 2);
    } else {
      return 0;
    }
  }
  int rangeBitwiseAnd(int left, int right) {
    return _range(left, right, (1 << 30), (1 << 30));
  }

  // leftとrightがゼロになるまで、その半分を比較し続ければ、何ビットシフトすればいいか分かる
  // int rangeBitwiseAnd(int left, int right) {
  //   int shift = 0;
  //   while (left < right) {
  //     left >>= 1;
  //     right >>= 1;
  //     shift++;
  //   }
  //   return left << shift;
  // }
};

int main() {
  Solution s;
  // auto output = s.rangeBitwiseAnd(5, 7);
  // auto output = s.rangeBitwiseAnd(6, 7);
  // auto output = s.rangeBitwiseAnd(0, 0);
  // auto output = s.rangeBitwiseAnd(1, 1);
  // auto output = s.rangeBitwiseAnd(2, 2);
  auto output = s.rangeBitwiseAnd(4000000, 2147483646);
  return 0;
}
