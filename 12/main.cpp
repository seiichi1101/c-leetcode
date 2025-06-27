#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  string intToRoman(int num) {
    string res = "";
    int d = 1;
    while (num > 0) {
      int mod = num % 10;
      if (1 < mod && mod < 4) {
        while (mod > 0) {
          res = roman.at(d) + res;
          mod--;
        };
      } else if (5 < mod && mod < 9) {
        while (mod > 5) {
          res = roman.at(d) + res;
          mod--;
        };
        res = roman.at(5 * d) + res;
      } else {
        res = roman.at(mod * d) + res;
      }
      num /= 10;
      d *= 10;
    }
    return res;
  }

private:
  static const unordered_map<int, string> roman;
};
const unordered_map<int, string> Solution::roman = {
    {0, ""},     {1, "I"},   {4, "IV"},   {5, "V"},    {9, "IX"},
    {10, "X"},   {40, "XL"}, {50, "L"},   {90, "XC"},  {100, "C"},
    {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"},
};

int main() {
  Solution s;
  int input = 3749;
  auto output = s.intToRoman(input);
  return 0;
}
