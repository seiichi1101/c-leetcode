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
  long long maximumTripletValue(vector<int> &nums)
  {
    int n = nums.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
        }
      }
    }
    return res;
  }
};
// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::maximumTripletValue); // CHANGE FOR PROBLEM
}
#endif
