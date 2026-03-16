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
  // Brute Force O(n^2)
  // char findKthBit(int n, int k) {
  //   string s = "0";
  //   for (size_t i = 1; i < k; i += i + 1) {
  //     string tmp = "";
  //     for (int j = s.size() - 1; j >= 0; j--) {
  //       tmp += s[j] == '1' ? '0' : '1';
  //     }

  //     s += "1" + tmp;
  //   }

  //   return s[k - 1];
  // }

  // O(n)
  char findKthBit(int n, int k) {
    int cnt = 0;
    string s = "0";
    int size = 1 << n;

    while (k > 1) {
      if (size / 2 == k)
        return cnt % 2 == 0 ? '1' : '0';
      if (size / 2 < k) {
        cnt++;
        k = size - k;
      }

      size /= 2;
    }

    return cnt % 2 == 0 ? '0' : '1';
  }
};

int main() {
  Solution s;
  // assert(s.findKthBit(3, 1) == '0');
  assert(s.findKthBit(4, 11) == '1');
  // assert(s.findKthBit(20, 1048575) == '0');
  return 0;
}
