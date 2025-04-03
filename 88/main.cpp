#include <bits/stdc++.h>
#include <iostream>
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
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    std::vector<int> res;
    int i = 0, j = 0;
    while (i < m || j < n)
    {
      // std::cout << i << j << std::endl;
      if (i >= m)
      {
        res.push_back(nums2[j]);
        j++;
      }
      else if (j >= n)
      {
        res.push_back(nums1[i]);
        i++;
      }
      else if (nums1[i] < nums2[j])
      {
        res.push_back(nums1[i]);
        i++;
      }
      else
      {
        res.push_back(nums2[j]);
        j++;
      }
    }
    nums1 = res;
  }
};
// ----- CHANGE FOR PROBLEM -----

#ifdef LC_LOCAL
int main()
{
  cin.tie(0)->ios_base::sync_with_stdio(false);
  exec(&Solution::merge); // CHANGE FOR PROBLEM
}
#endif
