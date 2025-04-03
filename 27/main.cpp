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
  int removeElement(vector<int> &nums, int val)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    if (nums.size() == 1)
    {
      if (nums[0] == val)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }

    int i = 0, j = 1;

    while (j < nums.size())
    {
      if (nums[i] == val)
      {
        if (nums[j] == val)
        {
          j++;
        }
        else
        {
          std::swap(nums[i], nums[j]);
          i++, j++;
        }
      }
      else
      {
        i++, j++;
      }
    }

    if (nums[i] == val)
    {
      return i;
    }
    else
    {
      return i + 1;
    }
  }
};
// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::removeElement); // CHANGE FOR PROBLEM
}
#endif
