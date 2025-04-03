#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 2)
    {
      return n;
    }

    int i = 1;
    for (size_t j = 1; j < nums.size(); j++)
    {
      if (nums[i - 1] != nums[j])
      {
        nums[i] = nums[j];
        i++;
      }
    }
    return i;
  }
};

int main()
{
  Solution s;
  // vector<int> input = {1, 1};
  // vector<int> input = {1, 2};
  // vector<int> input = {1, 1, 2};
  vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int output = s.removeDuplicates(input);
  return 0;
}
