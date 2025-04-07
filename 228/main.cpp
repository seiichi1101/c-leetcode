#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return vector<string>{};
    }

    vector<string> res;
    int head = 0;
    for (size_t i = 1; i < nums.size(); i++)
    {
      if ((nums[i - 1] + 1) != nums[i])
      {
        string str = to_string(nums[head]);
        if (head != i - 1)
        {
          str += "->" + to_string(nums[i - 1]);
        }

        res.push_back(str);
        head = i;
      }
    }

    if (head != nums.size() - 1)
    {
      res.push_back((to_string(nums[head]) + "->" + to_string(nums[nums.size() - 1])));
    }
    else
    {
      res.push_back(to_string(nums[nums.size() - 1]));
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> input = {0, 1, 2, 4, 5, 7};
  // vector<int> input = {0, 2, 3, 4, 6, 8, 9};
  auto output = s.summaryRanges(input);
  return 0;
}
