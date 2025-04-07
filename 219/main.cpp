#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      if (map.find(nums[i]) != map.end())
      {
        if ((i - map[nums[i]]) <= k)
        {
          return true;
        }
        else
        {
          map[nums[i]] = i;
        }
      }
      else
      {
        map[nums[i]] = i;
      }
    }

    return false;
  }
};

int main()
{
  Solution s;
  vector<int> input1 = {1, 2, 3, 1, 2, 3};
  int input2 = 2;
  auto output = s.containsNearbyDuplicate(input1, input2);
  return 0;
}
