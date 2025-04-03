#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    // sorting approach
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() / 2];

    // Boyer-Moore approach
    int count = 0;
    int candidate;

    for (int &num : nums)
    {
      if (count == 0)
      {
        candidate = num;
      }
      count += (num == candidate) ? 1 : -1;
    }

    return candidate;
  }
};

int main()
{
  Solution s;
  vector<int> input = {3, 2, 3};
  int output = s.majorityElement(input);
  return 0;
}
