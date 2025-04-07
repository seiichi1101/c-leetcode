#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
  bool isHappy(int n)
  {
    unordered_set<int> map = {n};
    while (true)
    {
      int next_n = 0;
      while (n > 0)
      {
        next_n += (n % 10) * (n % 10);
        n /= 10;
      }

      if (next_n == 1)
      {
        return true;
      }
      else if (map.find(next_n) != map.end())
      {
        return false;
      }
      else
      {
        map.insert(next_n);
        n = next_n;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  // int input = 19;
  int input = 2;
  auto output = s.isHappy(input);
  return 0;
}
