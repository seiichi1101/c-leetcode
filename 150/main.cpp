#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  vector<int>
  twoSum(vector<int> &nums, int target)
  {
    vector<int> res;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      if (map.find(nums[i]) != map.end())
      {
        res = {map[nums[i]], i};
        return res;
      }
      else
      {
        map[target - nums[i]] = i;
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> input1 = {2, 7, 11, 15};
  int input2 = 9;
  auto output = s.twoSum(input1, input2);
  return 0;
}
