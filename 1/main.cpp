#include <bits/stdc++.h>
using namespace std;

#ifdef LC_LOCAL
#include "parser.hpp"
#else
#define dbg(...)
#endif

class Solution
{
public:
  vector<int>
  twoSum(vector<int> &nums, int target)
  {
    int res1 = 0;
    int res2 = 0;
    std::unordered_map<int, int> dp;
    size_t i = 0;

    for (; i < nums.size(); i++)
    {
      if (dp.empty())
      {
        dp[target - nums[i]] = i;
        continue;
      }
      else
      {
        if (dp.find(nums[i]) != dp.end())
        {
          res1 = dp[nums[i]];
          res2 = i;
          break;
        }
        dp[target - nums[i]] = i;
      }
    }
    return vector<int>{res1, res2};
  }
};

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::twoSum);
}
#endif
