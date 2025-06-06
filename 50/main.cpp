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
  // 基本的な考え方は、乗数による計算のスキップ
  // ex) x = 2, n = 7
  // 1回目:2 -> 2回目:4(2*2) -> 3回目:8(4*2) -> 4回目:16(8*2) ->
  // 5回目:32(16*2) -> 6回目:64(32*2) -> 7回目:128(64*2) -> 8回目:256(128*2)
  // 上記みたいに、一回ずつxをかけていくのではなく、
  // １回目:2 -> 2回目:4(2*2) -> 4回目:16(4*4) -> 16回目:(16*16)
  // みたいに、x*xでスキップできる間の計算はスキップするという考え方
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }

    long long size = n;
    if (size < 0) {
      size = -1 * size;
      x = 1.0 / x;
    }

    double res = 1;
    while (size > 0) {
      // 奇数だとx*xが成立しないので、まず１回分ずらしてsizeを偶数にする
      if (size % 2 == 1) {
        res = res * x;
        size -= 1;
      }
      // 偶数なので、x*xで必要計算回数を省略する
      x = x * x;
      size = size / 2;
    }
    return res;
  }
};

int main() {
  Solution s;
  // double x = 2.0;
  // int n = 10;
  double x = 2.0;
  int n = 8;
  // double x = 2.1;
  // int n = 3;
  // double x = 2.0;
  // int n = -2;
  // double x = 1.0;
  // int n = 2147483647;
  // double x = 2.0;
  // int n = -2147483648;
  auto output = s.myPow(x, n);
  return 0;
}
