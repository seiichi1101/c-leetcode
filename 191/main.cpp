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
  // int hammingWeight(int n) {
  //   int cnt = 0;
  //   while (n > 1) {
  //     if (n % 2 == 1) {
  //       cnt++;
  //     }
  //     n = n / 2;
  //   }

  //   return cnt + 1;
  // }
  int hammingWeight(int n) {
    int cnt = 0;
    while (n > 0) {
      n = n &
          (n -
           1); // 1を減算したものとANDをとるのを繰り返すことで、右から順に1bit立っている部分を打ち消すしながら進めることができる。
      cnt++;
    }
    return cnt;
  }
};

int main() {
  Solution s;
  int input = 11;
  auto output = s.hammingWeight(input);
  return 0;
}
