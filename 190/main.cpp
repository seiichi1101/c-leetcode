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
  // uint32_t reverseBits(uint32_t n) {
  //   string bitstr = bitset<32>(n).to_string();
  //   uint32_t res = 0;
  //   long coeff = 1;
  //   for (auto &&c : bitstr) {
  //     if (c == '1') {
  //       res += coeff;
  //     }
  //     coeff = coeff * 2;
  //   }
  //   return res;
  // }
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int shift = 31;
    while (shift >= 0) {
      res += (n & 1) << shift; // 右端だけ取得するためにシフト
      n = n >> 1;              // 右端がいらなくなるのでシフトして捨てる
      shift--;                 // 1bit分減ったのでシフト数も減らす
    }

    return res;
  }
};

int main() {
  Solution s;
  uint32_t input = stoi("00000010100101000001111010011100", nullptr, 2);
  auto output = s.reverseBits(input);
  return 0;
}
