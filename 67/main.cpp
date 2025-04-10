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
#include <valarray>
#include <vector>

using namespace std;

class Solution {
public:
  // string addBinary(string a, string b) {
  //   auto sum = stoull(a, nullptr, 2) + stoull(b, nullptr, 2);
  //   string res = bitset<32>(sum).to_string();
  //   int i = 0;
  //   while (res[i] == '0') {
  //     i++;
  //   }

  //   return i == res.size() ? "0" : res.substr(i, res.size());
  // }

  string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    bool stack = 0;
    string res = "";
    while (i >= 0 || j >= 0) {
      if (i >= 0 && j >= 0) {
        if ((a[i] == '1' && b[j] == '1')) {
          if (stack) {
            res.push_back('1');
          } else {
            res.push_back('0');
          }
          stack = 1;
        } else if (a[i] == '0' && b[j] == '0') {
          if (stack) {
            res.push_back('1');
          } else {
            res.push_back('0');
          }
          stack = 0;
        } else {
          if (stack) {
            res.push_back('0');
            stack = 1;
          } else {
            res.push_back('1');
            stack = 0;
          }
        }
      } else if (i >= 0) {
        if (a[i] == '0') {
          if (stack) {
            res.push_back('1');
          } else {
            res.push_back('0');
          }
          stack = 0;
        } else {
          if (stack) {
            res.push_back('0');
            stack = 1;
          } else {
            res.push_back('1');
            stack = 0;
          }
        }
      } else if (j >= 0) {
        if (b[j] == '0') {
          if (stack) {
            res.push_back('1');
          } else {
            res.push_back('0');
          }
          stack = 0;
        } else {
          if (stack) {
            res.push_back('0');
            stack = 1;
          } else {
            res.push_back('1');
            stack = 0;
          }
        }
      }
      i--, j--;
    }

    reverse(res.begin(), res.end());
    return stack ? "1" + res : res;
  }
};

int main() {
  Solution s;
  // string input1 = "11";
  // string input2 = "1";
  string input1 = "1010";
  string input2 = "1011";
  // string input1 =
  // "101000001001001101100100000101011110110110011011101111111111"
  //                 "01000000101111001110001111100001101";
  // string input2 =
  // "110101001011101110001111100110001010100001101011101010000011"
  //                 "011011001011101111001100000011011110011";
  auto output = s.addBinary(input1, input2);
  return 0;
}
