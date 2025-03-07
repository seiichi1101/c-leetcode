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
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }
    long res = 0;
    int current = x;
    while (current >= 10)
    {
      res = res * 10 + (current % 10);
      current = current / 10;
    }
    res = res * 10 + current;
    return res == x;
  }
};
// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::isPalindrome); // CHANGE FOR PROBLEM
}
#endif
