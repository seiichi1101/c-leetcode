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
private:
  vector<int> ranges;
  size_t size = 0;

public:
  Solution(vector<int> &w) {
    ranges.push_back(w[0]);
    for (size_t i = 1; i < w.size(); i++) {
      ranges.push_back(ranges[i - 1] + w[i]);
    }
    size = ranges.size();
  }

  unsigned bounded_rand(unsigned range) {
    for (unsigned x, r;;)
      if (x = rand(), r = x % range, x - r <= -range)
        return r;
  }
  // own search
  // int pickIndex() {
  //   int val = 1 + bounded_rand(ranges[size - 1]);

  //   // binary search
  //   int l = 0, r = size;
  //   int mid = (r - l) / 2;
  //   while (0 < mid && mid <= size - 1) {
  //     if (ranges[mid - 1] < val && val <= ranges[mid])
  //       return mid;
  //     else if (val <= ranges[mid - 1]) {
  //       r = mid;
  //     } else {
  //       l = mid;
  //     }
  //     mid = (r + l) / 2;
  //   }

  //   return mid;
  // }

  int pickIndex() {
    int n = rand() % ranges[ranges.size() - 1];
    // 内部でBinary Searchしてるっぽい
    auto it = upper_bound(ranges.begin(), ranges.end(), n);
    return it - ranges.begin();
  }
};

int main() {
  // vector<int> input = {{1}};
  // vector<int> input = {{1, 3}};
  // vector<int> input = {{4, 2}};
  // vector<int> input = {{3, 14, 1, 7}};
  vector<int> input = {{10, 7, 8, 10}};
  Solution *s = new Solution(input);
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  cout << s->pickIndex() << '\n';
  return 0;
}
