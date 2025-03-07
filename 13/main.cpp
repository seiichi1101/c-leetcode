#include <bits/stdc++.h>
using namespace std;

#ifdef LC_LOCAL
#include "parser.hpp"
#else
#define dbg(...)
#endif

// ----- CHANGE FOR PROBLEM -----
class Solution
{
public:
  int romanToInt(string s)
  {
    int res = 0;
    size_t i = 0;
    while (i + 1 < s.length())
    {
      if (roman.find(std::string() + s[i] + s[i + 1]) != roman.end())
      {
        res += roman.at(s.substr(i, 2));
        i += 2;
      }
      else
      {
        res += roman.at(s.substr(i, 1));
        i += 1;
      }
    }

    if (i < s.length())
    {
      res += roman.at(s.substr(s.length() - 1, 1));
    }

    return res;
  }

private:
  static const std::unordered_map<string, int> roman;
};
const std::unordered_map<string, int> Solution::roman = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000},
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900},
};

// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::romanToInt); // CHANGE FOR PROBLEM
}
#endif
