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
  int singleNumber(vector<int> &nums) {
    int once = 0, twice = 0;
    // num = 2 (010)
    // 1回出現した時だけ残すようにうまくXORをトグルとして利用している
    // --- 1回目の出現 ---
    //    1回出現したビットを記録
    //    once  = (000 XOR 010) AND (NOT 000) = 010 AND 111 = 010 (2)
    //    2回目の出現はまだない
    //    twice = (000 XOR 010) AND (NOT 010) = 010 AND 101 = 000 (0)
    // --- 2回目の出現 ---
    //    1回出現していたビットが取り消される
    //    once  = (010 XOR 010) AND (NOT 000) = 000 AND 111 = 000 (0)
    //    2回出現したビットを記録
    //    twice = (000 XOR 010) AND (NOT000) = 010 AND 111 = 010 (2)
    // --- 3回目の出現 ---
    //    3回出現したビットはリセット
    //    once  = (000 XOR 010) AND (NOT 010) = 010 AND 101 = 000 (0)
    //    3回出現したビットはリセット
    //    twice = (010 XOR 010) AND (NOT 000) = 000AND 111 = 000 (0)
    for (auto &&n : nums) {
      once = (once ^ n) & (~twice);
      twice = (twice ^ n) & (~once);
    }
    return once;
  }
};

int main() {
  Solution s;
  vector<int> input = {2, 2, 2, 3};
  auto output = s.singleNumber(input);
  return 0;
}
