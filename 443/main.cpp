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
  vector<char> int_to_char(int num) {
    vector<char> res;
    while (num > 9) {
      int n = num % 10;
      num = num / 10;
      res.push_back(n + '0');
    }
    res.push_back(num + '0');
    reverse(res.begin(), res.end());
    return res;
  }
  int compress(vector<char> &chars) {
    int cnt = 1;
    int insertion = 1;

    char prev = chars[0];
    for (int i = 1; i < chars.size(); i++) {
      if (chars[i] == prev) {
        cnt++;
      } else {
        if (cnt > 1) {
          vector<char> num_chars = int_to_char(cnt);
          for (int j = 0; j < num_chars.size(); j++) {
            chars[insertion + j] = num_chars[j];
          }
          chars[insertion + num_chars.size()] = chars[i];
          insertion = insertion + num_chars.size() + 1;
        } else {
          chars[insertion] = chars[i];
          insertion += 1;
        }
        prev = chars[i];
        cnt = 1;
      }
    }

    if (cnt > 1) {
      vector<char> num_chars = int_to_char(cnt);
      for (int j = 0; j < num_chars.size(); j++) {
        chars[insertion + j] = num_chars[j];
      }
      insertion = insertion + num_chars.size();
    }

    if (insertion < chars.size())
      chars.erase(chars.begin() + insertion, chars.end());
    return chars.size();
  }
};

int main() {
  Solution s;
  // vector<char> input = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  // vector<char> input = {'a'};
  // vector<char> input = {'a', 'b', 'b', 'b', 'b', 'b', 'b',
  //                       'b', 'b', 'b', 'b', 'b', 'b'};
  // vector<char> input = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
  // vector<char> input = {'a', 'a'};
  vector<char> input = {'a', 'a', 'a', 'a', 'a', 'b'};
  auto output = s.compress(input);
  // cout << output << "/n";
  // assert(output == 6);
  return 0;
}
