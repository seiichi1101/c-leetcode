#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int res = 0;
    int l = 10001, h = -1;

    for (size_t i = 1; i < prices.size(); i++)
    {
      if (prices[i - 1] < prices[i])
      {
        h = max(h, prices[i]);
        l = min(l, prices[i - 1]);
        res = max(res, h - l);
      }
      else if (prices[i - 1] > prices[i])
      {
        h = -1;
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  // vector<int> input = {7, 1, 5, 3, 6, 4};
  // vector<int> input = {1, 2};
  // vector<int> input = {2, 4, 1};
  // vector<int> input = {2, 1, 2, 0, 1};
  vector<int> input = {9999, 10000};
  int output = s.maxProfit(input);
  return 0;
}
