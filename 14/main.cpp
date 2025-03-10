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
  string longestCommonPrefix(vector<string> &strs)
  {
    string res = strs[0];
    for (size_t i = 1; i < strs.size(); i++)
    {
      size_t j = 0;
      while (j < res.size())
      {
        if (res[j] == strs[i][j])
        {
          j++;
        }
        else
        {
          break;
        }
      }
      res = res.substr(0, j);
    }
    return res;
  }
};
// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::longestCommonPrefix); // CHANGE FOR PROBLEM
}
#endif
